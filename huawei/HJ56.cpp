// 完全数计算

#include <iostream>
#include <limits>
#include <unordered_set>

using namespace std;

bool isPerfectNumber(int n)
{
    int                a = 2;
    int                b = numeric_limits<int>::max();
    unordered_set<int> quotients;
    while (a <= b && a < n)
    {
        if (n % a == 0)
        {
            b = n / a;
            quotients.emplace(a);
            quotients.emplace(b);
        }
        ++a;
    }
    int sum = 1;
    for (int quotient : quotients)
    {
        sum += quotient;
        if (sum > n)
            return false;
    }
    return sum == n;
}

int main()
{
    int n;
    cin >> n;
    if (n < 6)
    {
        cout << 0;
        return 0;
    }

    int amount = 0;
    for (int i = 6; i <= n; ++i)
    {
        if (isPerfectNumber(i))
            amount++;
    }

    cout << amount << "\n";
}
