/**
 * @file test1.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2023-08-21
 */

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <iostream>

class person {
 public:
  person() {}

  person(int age) : age_(age) {}

  person(bool male) : male_(male) {}

  person(int age, bool male) : age_(age), male_(male) {}

  int age() const { return age_; }

  bool male() const { return male_; }

 private:
  friend class boost::serialization::access;

  template <typename Archive>
  void serialize(Archive &ar, const unsigned int version) {
    ar &age_;
  }

  int age_;
  bool male_;
};

void save() {
  std::ofstream file("archive.txt");
  boost::archive::text_oarchive oa(file);
  person p(31, false);
  oa << p;
}

void load() {
  std::ifstream file("archive.txt");
  boost::archive::text_iarchive ia(file);
  person p;
  ia >> p;
  std::cout << p.age() << "," << p.male() << std::endl;
}

int main() {
  save();
  load();
}