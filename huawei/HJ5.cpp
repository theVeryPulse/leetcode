#include <cinttypes>
#include <string>
#include <iostream>
#include <unordered_map>

uint64_t decimal_value(char c)
{
    if (isdigit(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    uint64_t value = 0;
    uint64_t order = 1;
    for (size_t i = line.length() - 1; line[i] != 'x'; --i)
    {
        value += decimal_value(line[i]) * order;
        order *= 16;
    }
    std::cout << value;
}
