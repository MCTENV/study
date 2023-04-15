#include <iostream>
#include <memory>

using namespace std;

class Investment {
 private:
  /* data */
 public:
  Investment(/* args */);
  virtual ~Investment();
};

Investment::Investment(/* args */) {}

Investment::~Investment() { std::cout << "destory investment" << std::endl; }

class Stock : public Investment {
 private:
  /* data */
 public:
  Stock();
  ~Stock();
};

Stock::Stock() {}

Stock::~Stock() { std::cout << "destroy stock" << std::endl; }

class Bound : public Investment {
 private:
  /* data */
 public:
  Bound(/* args */);
  ~Bound();
};

Bound::Bound(/* args */) {}

Bound::~Bound() { std::cout << "destroy bound" << std::endl; }

template <typename... Ts>
auto makeInvestment(int args, Ts&&... params) {
  unique_ptr<Investment> pInv(nullptr);
  switch (args) {
    case 0:
      pInv.reset(new Stock());
      break;
    case 1:
      pInv.reset(new Bound());
      break;
  }
  return pInv;
}

int main(int argc, char const* argv[]) {
  cout << "hello" << endl;
  auto pInv = makeInvestment(0, "args");
  auto pInv1 = makeInvestment(1, "args");
  int length = 10;
  return 0;
}
