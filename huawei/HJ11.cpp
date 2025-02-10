// 数字颠倒

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    for (auto c = line.rbegin(); c != line.rend(); ++c)
        std::cout << *c;
    std::cout << "\n";
}
