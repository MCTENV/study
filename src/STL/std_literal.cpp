#include <chrono>
#include <iostream>

using namespace std;

constexpr std::chrono::milliseconds operator"" _ms(unsigned long long ms) {
  return std::chrono::milliseconds(ms);
}

decltype(auto) add(int a, int b) { return a + b; }

int main(int argc, char const* argv[]) {
  auto now_time = 5_ms;
  std::cout << now_time.count() << std::endl;
  decltype(auto) y = now_time;
  std::cout << y.count() << std::endl;
}
