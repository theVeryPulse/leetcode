// 合并表记录

#include <string>
#include <iostream>
#include <map>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::map<int, int> key_value_map;

    for (int total = std::stoi(line); total; --total)
    {
        std::getline(std::cin, line);
        int key = std::stoi(line);
        if (key_value_map.find(key) == key_value_map.end())
            key_value_map[key] = 0;
        key_value_map[key] += std::stoi(
            line.substr(line.find_last_of(' ') + 1));
    }
    for (auto key_value : key_value_map)
        std::cout << key_value.first << ' ' << key_value.second << '\n';
}
