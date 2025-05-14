/* 
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 */

#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s)
{
    char *left;
    char *right;

    left = s;
    right = s;

    while (*(right + 1))
        right++;
    while (*left && !isalnum(*left))
        left++;
    while (right >= s && !isalnum(*right))
        right--;

    if (left == right)
        return (true);
    while(left < right)
    {
        if (tolower(*left) != tolower(*right))
            return (false);
        left++;
        right--;
        while (*left && !isalnum(*left))
            left++;
        while (right >= s && !isalnum(*right))
            right--;
    }
    return (true);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char *string = " ";
    printf("%d\n", isPalindrome(string));
    return 0;
}
