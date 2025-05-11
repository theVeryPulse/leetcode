#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>

char* mergeAlternately(char* word1, char* word2)
{
    char*  merged = calloc(strlen(word1) + strlen(word2) + 1, 1);
    size_t i_m = 0;
    size_t i_1 = 0;
    size_t i_2 = 0;
    while (word1[i_1] && word2[i_2])
    {
        merged[i_m++] = word1[i_1++];
        merged[i_m++] = word2[i_2++];
    }
    while (word1[i_1])
        merged[i_m++] = word1[i_1++];
    while (word2[i_2])
        merged[i_m++] = word2[i_2++];
    merged[i_m] = '\0';
    return merged;
}

#include <stdio.h>

int main()
{
    char* word1 = "abc";
    char* word2 = "ABC";
    char* merged = mergeAlternately(word1, word2);
    printf("%s\n", merged);
    free(merged);
}

