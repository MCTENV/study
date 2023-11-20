#include <algorithm>
#include <boost/token_functions.hpp>
#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

int main(){
    using namespace boost;
    std::string s = "Hello world!";
    tokenizer<char_separator<char>> token(s);
    std::for_each(token.begin(), token.end(), [](std::string str){
        std::cout << str << std::endl;
    });
}