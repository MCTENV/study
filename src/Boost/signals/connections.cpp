#include <boost/signals2.hpp>
#include <boost/signals2/connection.hpp>
#include <boost/signals2/shared_connection_block.hpp>
#include <boost/signals2/trackable.hpp>
#include <iostream>

void func() { std::cout << "Hello World" << std::endl; }

class world : public boost::signals2::trackable {
 public:
  void hello() {
    std::cout << sn << std::endl;
    std::cout << "Hello World" << std::endl;
  }
  ~world() { std::cout << "deconstruct world" << std::endl; }

  int sn;
};

int main() {
  boost::signals2::signal<void()> s;
  {
    std::unique_ptr<world> w(new world());
    w->sn = 1024;
    s.connect(boost::bind(&world::hello, w.get()));
  }
  std::cout << s.num_slots() << std::endl;
  s();
  /// 函数虽然调用了，但是对象已经被析构，内存空间可能被回收，值也失效了
}