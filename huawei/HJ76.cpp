// 尼科彻斯定理

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int part = num * num - num + 1;
    for (int i = 0; i < num; ++i)
    {
        cout << part;
        if (i != num - 1)
            cout << "+";
        part += 2;
    }
}
