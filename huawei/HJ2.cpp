// 计算某字符出现次数

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::string to_search;
    std::getline(std::cin, to_search);
    char c = to_search[0];
    size_t total = 0;
    if (isdigit(c) || isspace(c))
    {
        for (char to_check : line)
        {
            if (to_check == c)
                ++total;
        }
    }
    else if (isalpha(c))
    {
        char c_other = (islower(c)) ? toupper(c) : tolower(c);
        for (char to_check : line)
        {
            if (to_check == c || to_check == c_other)
                ++total;
        }
    }
    std::cout << total << '\n';
}
