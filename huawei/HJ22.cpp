// 汽水瓶

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> drinks_vector;
    while (true)
    {
        string line;
        getline(cin, line);
        if (cin.eof() || line == "0")
            break;
        int bottles = stoi(line);
        int drinks = 0;
        while (bottles >= 3)
        {
            bottles -= 3;
            drinks  += 1;
            bottles += 1;
        }
        if (bottles == 2)
        {
            bottles += 1;
            bottles -= 3;
            drinks  += 1;
            bottles += 1;
        }
        drinks_vector.push_back(drinks);
    }
    for (int drinks : drinks_vector)
        cout << drinks << "\n";
}
