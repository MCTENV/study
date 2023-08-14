/**
 * @file template.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-08-07
 */

#include <boost/type_index.hpp>
#include <iostream>
#include <ostream>
#include <utility>

class [[deprecated("Test Type deprecated")]] Type {
 public:
  Type() {}
  Type(int t) : t_(t) { std::cout << "constructor" << std::endl; }
  Type(const Type& t) : t_(t.t_) { std::cout << "copy" << std::endl; }
  Type(Type && t) : t_(t.t_) { std::cout << "move" << std::endl; }

  Type& operator=(const Type& t) {
    t_ = t.t_;
    std::cout << "copy assignment" << std::endl;
    return *this;
  }

  Type& operator=(Type&& t) {
    t_ = t.t_;
    std::cout << "move assignment" << std::endl;
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& out, const Type& t) {
    out << t.t_;
    return out;
  }

  Type& change() { return *this; }

  void setT(int t) { t_ = t; }

 private:
  int t_;
};

void copy(const Type& t) { std::cout << "lvalue reference" << std::endl; }

void copy(Type&& t) { std::cout << "rvalue reference" << std::endl; }

template <class T>
void func(T&& t) {
  static int counter = 1;
  std::cout << boost::typeindex::type_id_with_cvr<T>().pretty_name()
            << std::endl;
  t.setT(counter);
  std::cout << counter++ << std::endl;

  copy(std::forward<T>(t));
}

int main() {
  Type a = 0;
  Type&& t = Type(a);
  Type& b = a;
  auto&& c = b;
  func(a);
  func(t);  // lvalue reference

  func(std::forward<Type>(t));  // rvalue reference
  func(Type(a));                // rvalue reference

  copy(std::forward<Type>(c));
}