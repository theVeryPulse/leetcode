#include <string>
#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    size_t dot_pos = line.find_first_of('.');
    int value = std::stoi(line.substr(0, dot_pos));
    if (line[dot_pos + 1] - '0' >= 5)
        ++value;
    std::cout << value;
}
