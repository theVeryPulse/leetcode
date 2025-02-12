// 查找组成一个偶数最接近的两个素数

#include <iostream>

using namespace std;

bool isPrimeNumber(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    cin >> num;
    for (int q = num / 2; q < num; q++)
    {
        if (isPrimeNumber(q) && isPrimeNumber(num - q))
        {
            cout << num - q << "\n" << q << "\n";
            return 0;
        }
    }
}