#include <iostream>
#include <locale>
#include <cstring>

std::ostream& operator<<(std::ostream& os, std::locale const& loc) {
  if (loc.name().length() <= 80) return os << loc.name() << '\n';

  for (const auto c : loc.name()) c != ';' ? os << c : os << "\n    ";
  return os << '\n';
}

int main() {
  std::locale l1;
  std::locale l2("en_US.UTF-8");
  std::locale l3(l1, l2, std::locale::ctype);
  std::cout << l3 << std::endl;
  std::cout << std::strcoll("ä", "z") << std::endl; 
}