/**
 * @file signal.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-08-23
 */

#include <boost/signals2.hpp>
#include <iostream>

void func(int slot) { std::cout << __func__ << slot << std::endl; }

void hello(int slot) { std::cout << __func__ << slot << std::endl; }

int main() {
  boost::signals2::signal<void(int)> s;
  auto f = [](int slot) { std::cout << __func__ << slot << std::endl; };
  s.connect(1, func);
  s.connect(0, hello);
  s.connect(1, f);
  s(5);
  s.disconnect_all_slots();
  s(6);
}
