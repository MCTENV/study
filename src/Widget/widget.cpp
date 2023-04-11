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

Widget::Widget() : pImpl(make_unique<Impl>()) {
  std::cout << "Widget created" << std::endl;
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

// void Widget::setName(const chen::string &str) { pImpl->name = str; }

// void Widget::setName(chen::string &&str) { pImpl->name = std::move(str); }
