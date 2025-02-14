// 字符逆序

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for (auto c = s.rbegin(); c != s.rend(); ++c)
        cout << *c;
    cout << endl;
}
