/**
 * @file main.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-06
 */
#include <iostream>

#include "Widget/widget.h"

using namespace std;

int main(int argc, char const* argv[]) {
  auto spw = make_shared<Widget>(Widget());
  int&& t = 10;
  std::cout << typeid(t).name() << std::endl;
  auto lt = std::move(t);
  std::cout << typeid(lt).name() << std::endl;
  return 0;
}
