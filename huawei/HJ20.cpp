#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool hasAtLeastThreeTypes(const string& password)
{
    int upper = 0;
    int lower = 0;
    int num = 0;
    int special = 0;
    for (char c : password)
    {
        if (isupper(c))
            upper = 1;
        else if (islower(c))
            lower = 1;
        else if (isdigit(c))
            num = 1;
        else
            special = 1;
    }
    return upper + lower + num + special >= 3;
}

bool hasTwoIdenticalSubstr(const string& password)
{
    for (size_t len = 3; len < password.length() / 2; ++len)
    {
        for (size_t pos = 0; pos < password.length() - len; ++pos)
        {
            string sub1 = password.substr(pos, len);
            // abc
            for (size_t search = pos + len; search < password.length(); ++search)
            {
                string sub2 = password.substr(search, len);
                if (sub1 == sub2)
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<string> results;
    while (true)
    {
        string password;
        getline(cin, password);
        if (cin.eof())
            break;
        if (password.length() < 8 ||
            !hasAtLeastThreeTypes(password) ||
            hasTwoIdenticalSubstr(password))
        {
            results.push_back("NG");
            continue;
        }
        results.push_back("OK");
    }
    for (auto result : results)
        cout << result << "\n";
}
