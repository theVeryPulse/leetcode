// 自守数

#include <iostream>
#include <string>

using namespace std;

bool isAutomorphic(int n)
{
    string self = to_string(n);
    string squared = to_string(n * n);
    for (int i = 1; i <= self.length(); ++i)
    {
        if (self[self.length() - i] != squared[squared.length() - i])
            return false;
    }
    return true;
}

int main()
{
    int range;
    cin >> range;
    ++range;
    int count = 0;
    for (int i = 0; i < range; ++i)
    {
        if (isAutomorphic(i))
            count++;
    }
    cout << count << "\n";
}
