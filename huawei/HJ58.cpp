// 输入n个数，输出最小的k个数

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < k; ++i)
    {
        cout << nums[i];
        if (i != k - 1)
            cout << " ";
    }
    cout << "\n";
}