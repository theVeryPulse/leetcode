#include <iostream>
#include <string>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    int counter = 0;
    for (size_t i = 0; i < line.length(); ++i)
    {
        std::cout << line[i];
        ++counter;
        if (counter == 8)
        {
            counter = 0;
            std::cout << "\n";
        }
    }
    if (counter == 0)
        return 0;
    while (counter < 8)
    {
        std::cout << "0";
        ++counter;
    }
    std::cout << '\n';
}
