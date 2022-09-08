#ifndef GADGET_H
#define GADGET_H

#include <string>

class Gadget {
 private:
  std::string id;
  int value;
  double dvalue;

 public:
  Gadget();
  ~Gadget();

  void print();
};

#endif  // GADGET_H