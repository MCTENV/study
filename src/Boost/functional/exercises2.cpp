#include <algorithm>
#include <boost/function.hpp>
#include <boost/lambda/lambda.hpp>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
  using func = boost::function<int(const char*)>;
  std::vector<func> processors;
  processors.push_back(std::atoi);
  processors.push_back(reinterpret_cast<int (*)(const char*)>(std::strlen));

  const char data[] = "1.23";

  for (auto func : processors) std::cout << func(data) << std::endl;
  std::for_each(processors.begin(), processors.end(),
                [data](func f) { std::cout << f(data) << std::endl; });
}