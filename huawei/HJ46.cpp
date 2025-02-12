// 截取字符串

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int    n;
    string s;
    cin >> s >> n;
    cout << s.substr(0, n);
}
