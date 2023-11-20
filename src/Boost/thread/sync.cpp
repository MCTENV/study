#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
#include <boost/thread/lock_options.hpp>
#include <boost/thread/lock_types.hpp>
#include <boost/thread/pthread/mutex.hpp>
#include <boost/thread/thread_time.hpp>
#include <iostream>

void wait(int seconds) {
  boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

boost::timed_mutex mutex;

int i = 0;
void thread() {
  try {
    for (; i < 5; ++i) {
      wait(1);
      boost::unique_lock<boost::timed_mutex> lock(mutex, boost::try_to_lock);
      if (!lock.owns_lock()) {
        lock.timed_lock(boost::get_system_time() +
                        boost::posix_time::seconds(1));
      }
      std::cout << "thread " << boost::this_thread::get_id() << ": " << i
                << std::endl;
      boost::timed_mutex *m = lock.release();
      m->unlock();
    }
  } catch (boost::thread_interrupted e) {
  }
}

int main() {
  boost::thread t1(thread), t2(thread);
  t1.join();
  t2.join();
}