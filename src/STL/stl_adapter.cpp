/**
 * @file stl_adapter.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-02
 */
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

#include "STL/composer.h"

using namespace std;

int main(int argc, char const* argv[]) {
  vector<int> vi1;
  vector<int> vi2{1, 2, 3, 4, 5};
  ifstream reader(string(PROJECT_PATH).append("/input.txt"),
                  ios::in | ios::binary);
  ofstream writer(string(PROJECT_PATH).append("/result.txt"),
                  ios::trunc | ios::binary);
  auto output_iter = ostream_iterator<int>(writer, " ");
  // auto input_iter = istreambuf_iterator<int>(reader);
  // auto eos = istreambuf_iterator<char>();
  // vi1.reserve(100);
  // vi1.assign(input_iter, eos);
  int number;
  while (reader >> number) {
    vi1.push_back(number);
  }

  // copy(vi1.begin(), vi1.end(), output_iter);
  // auto ans = count_if(vi1.begin(), vi1.end(), bind1st(less<int>(), 2));
  // std::cout << ans << std::endl;
  auto multi_plus2_minus2 =
      // chen::compose1(bind2nd(multiplies<int>(), 2), bind2nd(plus<int>(), 3));
      chen::compose2(multiplies<int>(), bind2nd(plus<int>(), 2),
                     bind2nd(minus<int>(), 2));

  transform(vi2.begin(), vi2.end(), output_iter, multi_plus2_minus2);
  // std::cout << multi_plus2_minus2(5) << std::endl;
  return 0;
}
