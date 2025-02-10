// 句子逆序
// 输入 one two three
// 输出 three two one

#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> words;

    size_t i = 0;
    while (i != std::string::npos)
    {
        i = line.find_first_not_of(' ', i);
        size_t word_end = line.find_first_of(' ', i);
        words.push_back(line.substr(i, word_end - i));
        i = word_end;
    }
    for (size_t i = words.size() - 1; i < words.size(); --i)
    {
        std::cout << words[i];
        if (i != 0)
            std::cout << " ";
    }
}
