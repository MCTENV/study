#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> strings;
  strings.push_back("Boost");
  strings.push_back("C++");
  strings.push_back("Libraries");

  std::vector<int> sizes;

  //   for (std::vector<std::string>::iterator it = strings.begin(); it !=
  //   strings.end(); ++it)
  // sizes.push_back(it->size());
  std::for_each(strings.begin(), strings.end(),
                [&sizes](std::string str) { sizes.push_back(str.size()); });

  //   for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end();
  //   ++it)
  //     std::cout << *it << std::endl;
  std::for_each(sizes.begin(), sizes.end(),
                [](int i) { std::cout << i << std::endl; });
}