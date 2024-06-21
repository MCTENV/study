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
  spw->setName("hello world");
  std::cout << spw->getName() << std::endl;
  
  return 0;
}
