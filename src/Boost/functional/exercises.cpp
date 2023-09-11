#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

class divide_by : public std::function<int(int, int)> {
 public:
  int operator()(int n, int div) const { return n / div; }
};

int main() {
  std::vector<int> numbers;
  numbers.push_back(10);
  numbers.push_back(20);
  numbers.push_back(30);

  //   std::transform(numbers.begin(), numbers.end(), numbers.begin(),
  //                  std::bind(divide_by(), std::placeholders::_1, 2));
  //   for (std::vector<int>::iterator it = numbers.begin(); it !=
  //   numbers.end();
  //    ++it)
  // std::cout << *it << std::endl;
  std::transform(numbers.begin(), numbers.end(), numbers.begin(),
                 [](int n) -> int { return n /= 2; });
  std::for_each(numbers.begin(), numbers.end(),
                [](int i) { std::cout << i << std::endl; });
  return 0;
}