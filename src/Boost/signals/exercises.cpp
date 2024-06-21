#include <boost/signals2.hpp>
#include <functional>
#include <iostream>

struct Event {
  int event;
  Event(int e) : event(e) {}
};

class Button {
 public:
  void add_handler(void(*func)(Event)) { s_.connect(func); }

  void remove_handler(void(*func)(Event)) { s_.disconnect(func); }

  void click(Event event) { s_(event); }

 private:
  boost::signals2::signal<void(Event)> s_;
};

int main() {
  auto click1 = [](Event e) { std::cout << "click " << e.event << std::endl; };
  auto click2 = [](Event e) { std::cout << "Click " << e.event << std::endl; };
  Button btn;
  btn.add_handler(click1);
  btn.add_handler(click2);

  btn.click(Event(3));
  btn.remove_handler(click1);

  btn.click(Event(1));
}
