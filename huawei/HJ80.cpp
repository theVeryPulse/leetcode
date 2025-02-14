// 整型数组合并

#include <iostream>
#include <set>

using namespace std;

void readNumbers(set<int>& nums, int len)
{
    for (int i = 0; i < len; ++i)
    {
        int num;
        cin >> num;
        nums.emplace(num);
    }
}

int main()
{
    int len;

    set<int> nums;
    cin >> len;
    readNumbers(nums, len);

    cin >> len;
    readNumbers(nums, len);

    for (auto num : nums)
        cout << num;
    cout << endl;
}