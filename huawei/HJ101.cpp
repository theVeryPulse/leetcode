// 排序

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    int descending_order;
    cin >> descending_order;

    sort(nums.begin(), nums.end());
    if (descending_order)
        reverse(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i)
    {
        cout << nums[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << "\n";
}