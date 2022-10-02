/**
 * @file stl_algorithm.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-26
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;

/**
 * @brief 打印向量
 * @tparam T 任意数据类型
 * @param  v vector<T>的对象
 * @return true 打印成功
 * @return false 打印失败
 */
template <typename T>
void println_vector(const vector<T> &v) {
  std::cout << "[";
  for (auto &n : v) {
    std::cout << n << ",";
  }
  std::cout << "\b]" << std::endl;
}

template <class T>
struct display {
  void operator()(const T &x) { std::cout << x << " "; }
};

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> nums(n);
  vector<int> others(n);
  // default_random_engine dre(time(0));
  int count = 0;
  generate(nums.begin(), nums.end(), [&]() { return count++; });
  generate(others.begin(), others.end(), [&]() { return count--; });
  // for_each(s1.begin(), s1.end(), display<int>());
  // println_vector(nums);
  // println_vector(others);
  //   println_vector(others);
  // int m = 0;
  // cin >> m;
  // rotate(nums.begin(), nums.begin() + n / 2, nums.end());
  // auto ans = stable_partition(nums.begin(), nums.end(),
  // [&](const int &n) { return n < m; });
  // std::cout << *ans << std::endl;
  // println_vector(nums);
  // println_vector(others);
  std::cout << *search_n(nums.begin(), nums.end(), 3, 8, less<int>())
            << std::endl;
  transform(nums.begin(), nums.end(), nums.begin(), nums.begin(), plus<int>());
  for_each(nums.begin(), nums.end(), display<int>());
  return 0;
}
