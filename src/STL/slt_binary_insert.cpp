/**
 * @file slt_binary_insert.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-03
 */
#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  std::generate(nums.begin(), nums.end(), []() -> int {
    static std::default_random_engine dre(std::time(0));
    return dre() % 100;
  });
  auto print_space = [](const int& n) { std::cout << n << " "; };
  std::for_each(nums.begin(), nums.end(), print_space);
  std::cout << std::endl;
  auto begin = nums.begin();
  for (int i = 2; i < n; i++) {
    auto lower = std::lower_bound(begin, begin + i, nums[i]);
    if (lower < begin + i) {  // copy [lower,begin+i) to [lower+1,)
      auto temp = nums[i];
      std::copy(lower, begin + i,
                lower + 1);  // @warning 重叠区域拷贝有风险吗？
      *lower = temp;
    }
  }
  std::for_each(nums.begin(), nums.end(), print_space);
  return 0;
}
