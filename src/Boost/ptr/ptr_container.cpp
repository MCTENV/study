/**
 * @file ptr_container.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-08-22
 */

#include <algorithm>
#include <boost/core/ref.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/ptr_container/ptr_container.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <functional>
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

using namespace boost::ptr_container;

class add : public std::function<void(int, int)> {
 public:
  void operator()(int i, int j) const { std::cout << i + j << std::endl; }
};

bool compare(int i, int j) { return i > j; }

void addprint(int i, int j, std::ostream &os) { os << i + j << std::endl; }

int main() {
  boost::ptr_vector<int> v;
  v.push_back(new int(2));
  v.push_back(new int(1));
  v.push_back(new int(5));
  std::sort(v.begin(), v.end(), boost::lambda::_1 < boost::lambda::_2);
  std::for_each(v.begin(), v.end(), boost::lambda::_1 *= boost::lambda::_1);
  std::for_each(v.begin(), v.end(), std::cout << boost::lambda::_1 << "\n");
}
