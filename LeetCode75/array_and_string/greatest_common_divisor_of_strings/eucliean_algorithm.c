#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>

#define MAX(a, b) ((a) >= (b) ? (a) : (b))
#define MIN(a, b) ((a) >= (b) ? (b) : (a))

char* gcdOfStrings(char* str1, char* str2)
{
    size_t total_len = strlen(str1) + strlen(str2);

    char* str1_str2 = (char*)calloc(total_len + 1, 1);
    strcat_s(str1_str2, total_len + 1, str1);
    strcat_s(str1_str2, total_len + 1, str2);

    char* str2_str1 = (char*)calloc(total_len + 1, 1);
    strcat_s(str2_str1, total_len + 1, str2);
    strcat_s(str2_str1, total_len + 1, str1);
    if (strcmp(str1_str2, str2_str1) != 0)
    {
        free(str1_str2);
        free(str2_str1);
        return (char*)calloc(1, sizeof(char));
    }
    free(str1_str2);
    free(str2_str1);

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t big = MAX(len1, len2);
    size_t small = MIN(len1, len2);
    while (small)
    {
        size_t small_tmp = small;
        small = big % small;
        big = small_tmp;
    }
    char* gcd = (char*)calloc(big + 1, sizeof(char));
    memcpy(gcd, str1, big);
    return gcd;
}

#include <stdio.h>

int main(void)
{
    char*       str1 = "ABAB";
    char*       str2 = "ABABAB";
    const char* gcd = gcdOfStrings(str1, str2);
    printf("%s\n", gcd);
}