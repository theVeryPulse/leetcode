// 最小公倍数

#include <iostream>

using namespace std;

int main()
{
    int smaller;
    int bigger;
    cin >> smaller >> bigger;
    if (smaller > bigger)
        swap(smaller, bigger);
    int lcm = 1;
    for (int i = 2; i <= smaller; ++i)
    {
        while (smaller % i == 0 && bigger % i == 0)
        {
            smaller /= i;
            bigger /= i;
            lcm *= i;
        }
    }
    lcm *= smaller * bigger;
    cout << lcm << endl;
}
