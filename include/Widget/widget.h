#ifndef WIDGET_H
#define WIDGET_H
#pragma once
#include <functional>
#include <memory>

#include "chen_string.h"

class Widget {
 public:
  Widget();
  ~Widget();
  Widget(Widget&& rhs);
  Widget& operator=(Widget&& rhs);

  Widget(const Widget& lhs);
  Widget& operator=(const Widget& lhs);

  // void setName(const chen::string& str);
  // void setName(chen::string&& str);
  template <typename T>
  void setName(T&& str) {
    std::cout << "universal reference" << std::endl;
    pImpl->name = std::forward<T>(str);
  }

 private:
  struct Impl {
    // Gadget g1, g2, g3;
    chen::string name;
    // std::vector<double> data;
  };
  std::unique_ptr<Impl> pImpl;
  std::function<void(const chen::string&)> func;
};

#endif  // WIDGET_H