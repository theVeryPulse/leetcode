// 字符个数统计

#include <string>
#include <iostream>
#include <unordered_set>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::unordered_set<char> track;
    for (char c : line)
        track.emplace(c);
    std::cout << track.size() << "\n";
}
