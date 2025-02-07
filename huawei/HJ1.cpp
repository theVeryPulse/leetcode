// 字符串最后一个单词长度

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    size_t begin = line.find_last_of(' ');
    size_t len = line.length() - 1 - begin;
    std::cout << len << "\n";
}
