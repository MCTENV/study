/**
 * @file stl_utility.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-03
 */

#include <algorithm>
#include <chrono>
#include <ctime>
#include <exception>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <random>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::cout << std::hypot(3.0, 4.0) << std::endl;
  std::shared_ptr<double> fptr = std::make_shared<double>(3);
  std::cout << std::modf(3.1415, fptr.get()) << std::endl;
  std::cout << *fptr << std::endl;
  auto a = NAN;
  std::cout << std::boolalpha << std::isnan(a) << "," << std::isinf(INFINITY)
            << "," << std::isfinite(a) << std::endl;
  return 0;
}
