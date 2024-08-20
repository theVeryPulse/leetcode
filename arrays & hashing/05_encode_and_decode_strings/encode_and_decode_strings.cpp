#include <string>
#include <vector>

class Solution
{
  public:

    std::string encode(std::vector<std::string>& strs)
    {
        std::string encoded;
        for (std::vector<std::string>::iterator str = strs.begin();
             str != strs.end(); ++str)
        {
            encoded.append(*str);
            encoded.append("#~");
        }
        return encoded;
    }

    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> decoded;
        std::string::const_iterator str_begin = s.begin();
        std::string::const_iterator str_end = s.begin();
        while (str_end != s.end())
        {
            if (*str_end == '#' && *(str_end + 1) == '~')
            {
                decoded.push_back(std::string(str_begin, str_end));
                str_end += 2;
                str_begin = str_end;
                if (str_end == s.end())
                    return decoded;
            }
            ++str_end;
        }
        return decoded;
    }
};

#include <iostream>

int main()
{
    Solution solution;
    std::vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    std::string encoded = solution.encode(str_vec);
    std::cout << encoded << "\n";
    std::vector<std::string> decoded_strs = solution.decode(encoded);
    for (std::vector<std::string>::const_iterator str = decoded_strs.begin();
         str != decoded_strs.end(); ++str)
    {
        std::cout << *str << "\n";
    }
}
