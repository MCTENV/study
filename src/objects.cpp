
class Dopey {
 public:
  Dopey() {}

 private:
  int a;
};

class Sneezy {
 public:
  Sneezy() {}
  Sneezy(int b) : b(b) {}

 private:
  int b;
};

class Bashful {
 public:
  Bashful(){};

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
  return 0;
}