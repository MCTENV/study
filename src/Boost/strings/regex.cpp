#include <boost/lambda/lambda.hpp>
#include <boost/regex.hpp>
#include <boost/regex/v4/regex.hpp>
#include <boost/regex/v4/regex_replace.hpp>
#include <boost/regex/v4/regex_search.hpp>
#include <iostream>
#include <string>

int main() {
  std::string s = "hello world";
  using namespace boost;
  regex expr("(\\w+)\\s(\\w+)");
  smatch what;
  if (regex_search(s, what, expr)) {
    std::for_each(what.begin(), what.end(),
                  std::cout << lambda::_1 << "\n");
  }
  std::string fmt("\\2 \\1");
  std::cout << regex_replace(s, expr, fmt) << std::endl;
}