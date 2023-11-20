#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/regex.hpp>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s = "BBoris Schälingg";
  std::cout << boost::algorithm::to_upper_copy(s) << std::endl;
  std::cout << boost::algorithm::to_lower_copy(s) << std::endl;
  std::vector<std::string> v;
  v.push_back("hello");
  v.push_back("world");
  v.push_back("!");
  std::cout << boost::algorithm::join(v, " ") << std::endl;
  std::cout << boost::algorithm::replace_all_copy(s, "i", "I") << std::endl;
  std::cout << boost::algorithm::trim_copy_if(
                   s, boost::lambda::_1 == 'g' or boost::lambda::_1 == 'B')
            << std::endl;
  std::cout << boost::algorithm::trim_copy_if(
                   s, boost::algorithm::is_any_of("Boing"))
            << std::endl;
  std::cout << boost::algorithm::starts_with(s, "BBoris") << std::endl;
  std::cout << boost::algorithm::contains(s, "is") << std::endl;
  std::cout << boost::algorithm::lexicographical_compare(s, "Boris")
            << std::endl;
  v.clear();
  boost::algorithm::split(v, s, boost::algorithm::is_space());
  std::cout << v.size() << std::endl;

  auto r = boost::algorithm::find_regex(s, boost::regex("\\w+\\s\\w+"));
  std::cout << r << std::endl;
}