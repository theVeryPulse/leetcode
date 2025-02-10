// 字符串排序

#include <set>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int line_amount = std::stoi(line);
    std::multiset<std::string> string_set;
    while (line_amount)
    {
        std::getline(std::cin, line);
        string_set.emplace(line);
        --line_amount;
    }
    for (const auto& s: string_set)
        std::cout << s << "\n";
}
