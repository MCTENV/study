#ifndef WIDGET_H
#define WIDGET_H

#include <memory>

class Widget {
 public:
  Widget();
  ~Widget();
  Widget(Widget&& rhs);
  Widget& operator=(Widget&& rhs);

  Widget(const Widget& lhs);
  Widget& operator=(const Widget& lhs);

 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;
};

#endif  // WIDGET_H