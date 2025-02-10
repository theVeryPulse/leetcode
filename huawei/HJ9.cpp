// 提取不重复的整数

#include <string>
#include <iostream>
#include <limits>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    bool track[10];
    for (size_t i = 0; i < 10; i++)
        track[i] = false;
    for (size_t i = line.length() - 1; i < line.length(); --i)
    {
        if (!track[line[i] - '0'])
        {
            track[line[i] - '0'] = true;
            std::cout << line[i];
        }
    }
    std::cout << "\n";
}
