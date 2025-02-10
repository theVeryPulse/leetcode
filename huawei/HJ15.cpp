// 求整数变量内存为1的bit的总量

#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int num = std::stoi(line);
    int bit_1_amount = 0;
    for (int n = 0; n < 32; n++)
    {
        bit_1_amount += num & 1;
        num >>= 1;
    }
    std::cout << bit_1_amount << "\n";
}
