
#include <cstdio>
class X {
 public:
  virtual void foo() = 0;
};
class Dopey : public virtual X {
 public:
  Dopey() {}
  void foo() override { printf("const char *__restrict format, ...\n"); }

 private:
  int a;
};

class Sneezy : public virtual X {
 public:
  Sneezy() {}
  Sneezy(int b) : b(b) {}
  void foo() override { printf("const char *__restrict format, ...\n"); }

 private:
  int b;
};

class Bashful : public virtual X {
 public:
  Bashful(){};
  void foo() { printf("const char *__restrict format, ...\n"); }

 private:
  int c;
};

class SnowWhite {
 public:
  Dopey dopey;
  Sneezy sneezy;
  Bashful bashful;

 private:
  int mumble;
};

int main(int argc, char* argv[]) {
  SnowWhite snowWhite;
  snowWhite.bashful.foo();
  return 0;
}
