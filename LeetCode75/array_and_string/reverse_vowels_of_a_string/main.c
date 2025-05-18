#include <stdbool.h>
#include <string.h>

static bool isVowel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a'
           || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseVowels(char* s)
{
    size_t left = 0;
    size_t len = strlen(s);
    size_t right = len - 1;
    while (left < right)
    {
        while (left < right && !isVowel(s[left]))
        {
            left++;
        }
        while (left < right && !isVowel(s[right]))
        {
            right--;
        }
        if (isVowel(s[left]) && isVowel(s[right]))
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
        left++;
        right = (right == 0) ? 0 : right - 1;
    }
    return s;
}

#include <stdio.h>

int main()
{
    char s[] = "aeiou";
    reverseVowels(s);
    printf("%s\n", s);
}