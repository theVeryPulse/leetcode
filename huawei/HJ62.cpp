// 查找输入整数二进制中1的个数

#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    cin >> a >> b;
    int bit_1_a = 0;
    int bit_1_b = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((1 << i & a) > 0)
            ++bit_1_a;
        if ((1 << i & b) > 0)
            ++bit_1_b;
    }
    cout << bit_1_a << "\n" << bit_1_b << "\n";
}
