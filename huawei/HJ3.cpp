#include <set>
#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int amount = std::stoi(line);
    std::set<int> sorted;
    for (int i = 0; i < amount; ++i)
    {
        std::getline(std::cin, line);
        sorted.emplace(std::stoi(line));
    }
    for (int num : sorted)
        std::cout << num << "\n";
}
