#include <ctype.h>
#include <malloc.h>
#include <string.h>

static int calc_len(char* s)
{
    int len = 0;
    int i = 0;
    while (s[i])
    {
        if (isspace(s[i]))
        {
            len++;
            while (isspace(s[i]))
                i++;
        }
        while (s[i] && !isspace(s[i]))
        {
            len++;
            i++;
        }
    }
    return len;
}

char* reverseWords(char* s)
{
    char* reverse = (char*)calloc(calc_len(s) + 1, sizeof(char));
    int   write = 0;
    int   i = strlen(s) - 1;
    while (i >= 0)
    {
        while (i >= 0 && isspace(s[i]))
            --i;
        if (i < 0)
            break;

        const int word_end = i + 1;
        while (i >= 0 && !isspace(s[i]))
            --i;
        const int word_begin = i + 1;
        if (write != 0)
            reverse[write++] = ' ';
        for (int src_i = word_begin; src_i < word_end; ++src_i)
            reverse[write++] = s[src_i];
    }
    reverse[write] = '\0';
    return reverse;
}

#include <stdio.h>

int main(void)
{
    char* s = "the sky is blue";
    char* reverse = reverseWords(s);
    printf("%s<\n", reverse);
}
