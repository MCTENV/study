#include <boost/format.hpp>
#include <boost/format/format_fwd.hpp>
#include <boost/format/group.hpp>
#include <ios>
#include <iostream>

int main() {
  std::cout << boost::format("%1%.%2%.%3%") % 1 % 2 % 3 << std::endl;
  std::cout << boost::format("%1%,%2%,%1%") % boost::io::group(std::showpos, 1) % 2 << std::endl;

}