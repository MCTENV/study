/**
 * @file stl_math.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-03
 */
#include <chrono>
#include <iostream>

/**
 * @brief 使用除法+模运算比内置函数std::div慢？并不是
 * @return false
 */
bool faster() {
  int rem, quot;
  std::div_t dv;
  // 尽量不要使用high_resolution_clock，不同标准库实现之间实现并不一致
  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < 1e9; i++) {
    rem = i % 1313131;
    quot = i / 1313131;
    // rem += quot;
  }
  auto end = std::chrono::steady_clock::now();
  auto div_after_mod =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
  start = std::chrono::steady_clock::now();
  for (int i = 0; i < 1e9; i++) {
    dv = std::div(i, 1313131);
    // dv.rem += dv.quot;
  }
  end = std::chrono::steady_clock::now();
  auto div_mod =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
  dv.rem = rem;
  dv.quot = quot;
  return div_mod < div_after_mod;
}

int main(int argc, char const *argv[]) {
  std::cout << std::boolalpha << faster() << std::endl;
  return 0;
}
