#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
#include <boost/thread/exceptions.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void thread() {
  try {
    for (int i = 0; i < 5; ++i) {
      wait(1);
      std::cout << i << std::endl;
    }
  } catch (boost::thread_interrupted e) {
  }
}

int main() {
  std::cout << boost::thread::hardware_concurrency() << std::endl;
  boost::thread t(thread);
  wait(3);
  t.interrupt();
  t.join();
}