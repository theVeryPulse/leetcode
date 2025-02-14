// 等差数列

#include <iostream>

using namespace std;

int main()
{
    int nth_sum;
    cin >> nth_sum;
    int       sum = 0;
    const int diff = 3;
    int       item = 2;
    for (int i = 0; i < nth_sum; ++i)
    {
        sum += item;
        item += diff;
    }
    cout << sum << "\n";
}
