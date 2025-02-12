/*
每一年中都有12个月份。其中1,3,5,7,8,10,12月每个月有31天；
4,6,9,11月每个月有30天；而对于2月，闰年时有29天，平年时有28天。
现在，对应输入的日期，计算这是这一年的第几天。

一个年份是闰年当且仅当它满足下列两种情况其中的一种：
- 这个年份是 4 的整数倍，但不是 100 的整数倍
- 这个年份是 400 的整数倍

Input:
2012 12 31
 */

#include <iostream>

using namespace std;

int main()
{
    int year;
    int month;
    int day;

    cin >> year >> month >> day;
    bool is_leap_year;
    is_leap_year = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int days_in_month[12] = {
        31,                     // 1
        is_leap_year ? 29 : 28, // 2
        31,                     // 3
        30,                     // 4
        31,                     // 5
        30,                     // 6
        31,                     // 7
        31,                     // 8
        30,                     // 9
        31,                     // 10
        30,                     // 11
        31                      // 12
    };

    int day_in_year = 0;
    for (int i = 0; i < month - 1; ++i)
        day_in_year += days_in_month[i];
    day_in_year += day;
    cout << day_in_year << endl;
}
