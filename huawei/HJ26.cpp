#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Letter
{
    Letter(char letter, bool is_upper) : letter_(letter), is_upper_(is_upper)
    {
    }
    char letter_;
    bool is_upper_;
};

int main()
{
    string line;
    getline(cin, line);

    vector<Letter> sorted_letters;
    for (char c : line)
    {
        if (isalpha(c))
            sorted_letters.emplace_back(Letter(tolower(c), isupper(c)));
    }
    stable_sort(
        sorted_letters.begin(), sorted_letters.end(),
        [](const Letter& a, const Letter& b) { return a.letter_ < b.letter_; });

    auto letter = sorted_letters.cbegin();
    for (char c : line)
    {
        if (isalpha(c))
        {
            cout << (char)((letter->is_upper_) ? toupper(letter->letter_)
                                               : letter->letter_);
            ++letter;
        }
        else
            cout << c;
    }
    cout << endl;
}
