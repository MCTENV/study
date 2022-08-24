#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class A {
 private:
  int n;
  float f;
  string s;

 public:
  A() { cout << "zero" << endl; }
  A(int n) : n(n) { cout << "i" << endl; }
  A(int n, float f) : n(n), f(f) { cout << "if" << endl; }
  A(int n, float f, string s) : n(n), f(f), s(s) { cout << "ifs" << endl; }
};

template <typename... Args>
shared_ptr<A> create(Args... args) {
  return shared_ptr<A>(new A(std::forward<Args>(args)...));
}


int main(int argc, char const* argv[]) {
  vector<int> first({1, 2, 3, 4});
  auto current = first;
  do {
    for (auto& i : first) {
      cout << i << ' ';
    }
    cout << endl;
    next_permutation(first.begin(), first.end());
  } while (current != first);

  return 0;
}
