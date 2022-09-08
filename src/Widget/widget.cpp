/**
 * @file widget.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-09-06
 */

#include "Widget/widget.h"

#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>

#include "Widget/gadget.h"

#if 201103L == 201103L
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

struct Widget::Impl {
  Gadget g1, g2, g3;
  std::string name;
  std::vector<double> data;
};

Widget::Widget() : pImpl(make_unique<Impl>()) {
  pImpl->g1.print();
  pImpl->g2.print();
  pImpl->g3.print();
}

Widget::~Widget() = default;

Widget::Widget(Widget &&rhs) { pImpl = std::move(rhs.pImpl); }

Widget &Widget::operator=(Widget &&rhs) {
  pImpl = std::move(rhs.pImpl);
  return *this;
}

Widget::Widget(const Widget &lhs) : pImpl(make_unique<Impl>(*lhs.pImpl)) {}

Widget &Widget::operator=(const Widget &lhs) {
  *pImpl = *lhs.pImpl;
  return *this;
}