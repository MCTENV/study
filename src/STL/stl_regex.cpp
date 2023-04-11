/**
 * @file stl_regex.cpp
 * @brief
 * @author chenqi (chenqi@imudges.com)
 * @version 1.0
 * @date 2022-10-03
 */
#include <iostream>
#include <regex>
#include <string>

int main(int argc, char const *argv[]) {
  std::regex word_reg("(\\w+)");
  std::string str{
      "Some people, when confronted with a a problem, think "
      "\"I know, I'll use use regular expressions.\" "
      "Now they have two two problems."};
  auto word_begin = std::sregex_iterator(str.begin(), str.end(), word_reg);
  auto word_end = std::sregex_iterator();
  auto iter = word_begin;

  while (iter != word_end) {
    std::cout << iter->str() << std::endl;
    ++iter;
  }

  std::regex long_word_regex(R"(\w{1,9})");
  std::string new_str = std::regex_replace(str, long_word_regex, "{$&}");
  std::cout << new_str << std::endl;

  std::regex repet_word(R"(\b(?<word>\w+)\b\s+(?p=word)\b)", 
  std::regex_constants::grep);
  word_begin = std::sregex_iterator(str.begin(), str.end(), repet_word);
  iter = word_begin;
  while (iter != word_end) {
    std::cout << iter->str() << std::endl;
    ++iter;
  }

  std::regex email_regex(
      R"(^[a-z0-9A-Z]+[- | a-z0-9A-Z . _]+@([a-z0-9A-Z]+(-[a-z0-9A-Z]+)?\.)+[a-z]{2,}$)");
  while (std::cin >> str) {
    std::cout << std::boolalpha << std::regex_match(str, email_regex)
              << std::endl;
  }
  return 0;
}
