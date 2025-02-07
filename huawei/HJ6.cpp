// 质数因子

#include <iostream>
#include <string>
#include <vector>

bool isPrime(int n)
{
    int q = 2;
    while (q * q <= n)
    {
        if (n % q == 0)
            return false;
        ++q;
    }
    return true;
}

void printResults(std::vector<int>& quotients)
{
    for (size_t i = 0; i < quotients.size(); ++i)
    {
        std::cout << quotients[i];
        if (i != quotients.size() - 1)
            std::cout << " ";
    }
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> quotients;

    int num = std::stoi(line);
    int q = 2;
    while (num != 1)
    {
        if (isPrime(num))
        {
            quotients.push_back(num);
            break;
        }
        else if (isPrime(q) && num % q == 0)
        {
            num /= q;
            quotients.push_back(q);
        }
        else
            ++q;
    }
    printResults(quotients);
}
