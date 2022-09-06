#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#if __cplusplus == 201103L
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args) {
  cout << "self make unique" << endl;
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

int main(int argc, char const *argv[]) {
  auto upi = make_unique<int>(5);
  return 0;
}
