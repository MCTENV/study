#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>

namespace chen {
class string : public std::string {
 public:
  string() { std::cout << "constructor" << std::endl; }
  string(const char *str) : std::string(str) {
    std::cout << "constructor(const char *):" << str << std::endl;
  }
  string(const chen::string &str) : std::string(str) {
    std::cout << "constructor(const string&):" << str << std::endl;
  }
  string(chen::string &&str) : std::string(str) {
    std::cout << "constructor(string&&):" << str << std::endl;
  }
  ~string() { std::cout << "destructor" << *this << std::endl; }

  string &operator=(const string &rhs) {
    std::cout << "operator=(const string&)" << rhs << std::endl;
    return *this;
  }

  string &operator=(const char *rhs) {
    std::cout << "operator=(const char*)" << rhs << std::endl;
    return *this;
  }
};
}  // namespace chen

#endif  // STRING_H