#include <algorithm>
#include <boost/cstdint.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include <boost/thread/detail/thread.hpp>
#include <boost/thread/pthread/condition_variable_fwd.hpp>
#include <boost/thread/pthread/mutex.hpp>
#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>

uint64_t sum = 0;
boost::mutex mutex;
boost::condition_variable cond;

struct range {
  int s, e;
};

/**
 * @brief 函数简介
 * @param  r  参数简介
 * @return nothing
 */
void sum_range(range r) {
  uint64_t sum_tmp = 0;
  for (int i = r.s; i < r.e; ++i) {
    sum_tmp += i;
  }
  mutex.lock();
  sum += sum_tmp;
  mutex.unlock();
}

int main() {
  boost::posix_time::ptime start =
      boost::posix_time::microsec_clock::local_time();

  int num = boost::thread::hardware_concurrency();
  auto total = 1000000000;
  int interval = total / num;
  std::vector<boost::thread> threads;
  for (int s = 0, e = interval; true; s = e, e += interval) {
    range r{.s = s, .e = e};
    if (e >= total) {
      r.e = total;
      threads.emplace_back(boost::thread(sum_range, r));
      break;
    } else {
      threads.emplace_back(boost::thread(sum_range, r));
    }
  }
  std::for_each(threads.begin(), threads.end(),
                std::mem_fn(&boost::thread::join));

  boost::posix_time::ptime end =
      boost::posix_time::microsec_clock::local_time();
  std::cout << end - start << std::endl;

  std::cout << sum << std::endl;
}
// #include <boost/date_time/posix_time/posix_time.hpp>
// #include <boost/cstdint.hpp>
// #include <iostream>

// int main()
// {
//   boost::posix_time::ptime start =
//   boost::posix_time::microsec_clock::local_time();

//   boost::uint64_t sum = 0;
//   for (int i = 0; i < 1000000000; ++i)
//     sum += i;

//   boost::posix_time::ptime end =
//   boost::posix_time::microsec_clock::local_time(); std::cout << end - start
//   << std::endl;

//   std::cout << sum << std::endl;
// }