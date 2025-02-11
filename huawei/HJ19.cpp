/* 
D:\oblemsinnowcoder 12
D:\nowcoderproblemsinnowcoder 12
D:\nowcoder\problemsinnowcoder 13
D:\oj\problemsinnowcoder 13
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Err
{
  public:
    Err(string name, int line) : name_(name), line_(line)
    {
        appeared_counter_ = 1;
    }

    string name_;
    int    line_;
    int    appeared_counter_;
};

int main()
{
    // Parse input
    vector<Err> errors;
    for (size_t i = 0; !cin.eof(); ++i)
    {
        string path;
        int    line;
        cin >> path >> line;
        if (cin.eof())
            break;
        // get the error name
        string name;
        for (size_t j = path.length() - 1; j < path.length(); --j)
        {
            if (path[j - 1] == '\\' || j == path.length() - 16)
            {
                name = path.substr(j);
                break;
            }
        }
        // Update error if exists
        bool error_exists = false;
        for (auto& error : errors)
        {
            if (error.name_ == name && error.line_ == line) // find the error with matching name and line
            {
                ++error.appeared_counter_;
                error_exists = true;
                break;
            }
        }
        // Add error if doesn't exist
        if (!error_exists)
            errors.push_back(Err(name, line));
    }

    size_t last_eight = (errors.size() > 8) ? errors.size() - 8 : 0;
    for (size_t i = last_eight; i < errors.size(); i++)
    {
        const auto& error = errors[i];
        cout << error.name_ << " " << error.line_ << " "
             << error.appeared_counter_ << "\n";
    }
}
