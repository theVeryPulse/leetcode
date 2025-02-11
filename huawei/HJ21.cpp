#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cin >> line;
    for (char& c : line)
    {
        if (isupper(c))
        {
            c = tolower(c);
            c = (c == 'z') ? 'a' : c + 1;
        }
        else if (c >= 'a' && c <= 'c')
            c = '2';
        else if (c >= 'd' && c <= 'f')
            c = '3';
        else if (c >= 'g' && c <= 'i')
            c = '4';
        else if (c >= 'j' && c <= 'l')
            c = '5';
        else if (c >= 'm' && c <= 'o')
            c = '6';
        else if (c >= 'p' && c <= 's')
            c = '7';
        else if (c >= 't' && c <= 'v')
            c = '8';
        else if (c >= 'w' && c <= 'z')
            c = '9';
    }
    std::cout << line << endl;
}