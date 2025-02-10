// 数组中心位置

/*
给你一个整数数组nums，请计算数组的中心位置。数组的中心位置是数组的一个下标，
其左侧所有元素相乘
的积等于右侧所有元素相乘的积。数组第一个元素的左侧积为1，最后一个元素的右侧积为1。
如果数组有多
个中心位置，应该返回最靠近左边的那一个，如果数组不存在中心位置，返回-1

2 5 3   6  5   6
0 2 10  30 180 900
    180 30 6   0
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> nums;

    size_t i = 0;
    while (true)
    {
        if ((i = line.find_first_not_of(' ', i)) == std::string::npos)
            break;
        nums.push_back(std::stoi(line.substr(i, line.find_first_of(' ', i))));
        i = line.find_first_of(' ', i);
    }
    if (nums.size() <= 2)
    {
        std::cout << "-1\n";
        return 0;
    }

    std::vector<int> products(nums.size(), 1);
    for (i = 1; i < nums.size() - 1; ++i)
        products[i] = products[i - 1] * nums[i - 1];

    int back_produtcs = 1;
    for (i = nums.size() - 2; i < nums.size(); --i)
    {
        back_produtcs *= nums[i + 1];
        if (products[i] == back_produtcs)
        {
            std::cout << i << "\n";
            return 0;
        }
    }
    std::cout << "-1\n";
}
