#include <iostream>
#include <pthread.h>
#include <unistd.h>

const int NumberOfThreads = 10;

void *print_hello_world(void *tid) {
  sleep(1);
  std::cout << "Hello world, thread " << *(int *)tid << std::endl;
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  pthread_t threads[NumberOfThreads];
  int status;
  for (int i = 0; i < NumberOfThreads; ++i) {
    std::cout << "Main thread, create thread" << std::endl;
    status = pthread_create(&threads[i], nullptr, print_hello_world,
                            static_cast<void *>(&i));
    if (status != 0) {
      std::cout << "Fatal error" << std::endl;
      exit(status);
    }
  }
  void *ret;
  pthread_join(threads[NumberOfThreads - 1], &ret);
  return 0;
}