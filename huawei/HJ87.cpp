/*
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符

二、字母:
0 分: 没有字母
10 分: 密码里的字母全都是小（大）写字母
20 分: 密码里的字母符合”大小写混合“

三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字

四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号

五、奖励（只能选符合最多的那一种奖励）:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号

最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0:  非常弱（Very_Weak）

对应输出为：

VERY_SECURE
SECURE
VERY_STRONG
STRONG
AVERAGE
WEAK
VERY_WEAK

请根据输入的密码字符串，进行安全评定。

注：
字母：a-z, A-Z
数字：0-9
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./     (ASCII码：0x21~0x2F)
:;<=>?@             (ASCII码：0x3A~0x40)
[\]^_`              (ASCII码：0x5B~0x60)
{|}~                (ASCII码：0x7B~0x7E)

提示:
1 <= 字符串的长度<= 300
输入描述：
输入一个string的密码

输出描述：
输出密码等级
*/

#include <iostream>
#include <string>

using namespace std;

int lengthScore(const string& password)
{
    if (password.length() <= 4)
        return 5;
    else if (password.length() <= 7)
        return 10;
    else
        return 25;
}

int alphaScore(const string& password)
{
    bool has_lower = false;
    bool has_upper = false;
    for (char c : password)
    {
        if (islower(c))
            has_lower = true;
        else if (isupper(c))
            has_upper = true;
        if (has_lower && has_upper)
            return 20;
    }
    if (has_lower || has_upper)
        return 10;
    else
        return 0;
}

int digitScore(const string& password)
{
    int digit_amount = 0;
    for (char c : password)
    {
        if (isdigit(c))
            ++digit_amount;
        if (digit_amount > 1)
            return 20;
    }
    return (digit_amount) ? 10 : 0;
}

int signScore(const string& password)
{
    int sign_amount = 0;
    for (char c : password)
    {
        if (!isalnum(c))
            ++sign_amount;
        if (sign_amount > 1)
            return 25;
    }
    return (sign_amount) ? 10 : 0;
}

int bonusScore(const string& password)
{
    int has_lower = 0;
    int has_upper = 0;
    int has_digit = 0;
    int has_special = 0;
    for (char c : password)
    {
        if (islower(c))
            has_lower = 1;
        else if (isupper(c))
            has_upper = 1;
        else if (isdigit(c))
            has_digit = 1;
        else
            has_special = 1;
        if (has_lower + has_upper + has_digit + has_special == 4)
            return 5;
    }
    if ((has_lower | has_upper) + has_digit == 2)
        return 2;
    else //  if ((has_lower | has_upper) + has_digit + has_special == 3)
        return 3;
}

int main()
{
    string password;
    cin >> password;
    int score = 0;
    score += lengthScore(password);
    score += alphaScore(password);
    score += digitScore(password);
    score += signScore(password);
    score += bonusScore(password);
    if (score >= 90)
        cout << "VERY_SECURE\n";
    else if (score >= 80)
        cout << "SECURE\n";
    else if (score >= 70)
        cout << "VERY_STRONG\n";
    else if (score >= 60)
        cout << "STRONG\n";
    else if (score >= 50)
        cout << "AVERAGE\n";
    else if (score >= 25)
        cout << "WEAK\n";
    else if (score >= 0)
        cout << "VERY_WEAK\n";
}
