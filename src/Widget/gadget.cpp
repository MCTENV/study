/**
 * @file gadget.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-06
 */

#include "Widget/gadget.h"

#include <iostream>

Gadget::Gadget() { std::cout << "create Gadget" << std::endl; }

Gadget::~Gadget() {}

void Gadget::print() {
  std::cout << id << ":" << value << ",";
  std::cout << dvalue << std::endl;
}