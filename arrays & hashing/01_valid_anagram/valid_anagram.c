#include <stdbool.h>

bool isAnagram(char *s, char *t)
{
	int counter[26] = {0};
	int i;

	i = 0;
	while (s[i] && t[i])
	{
		counter[s[i] - 'a']++;
		counter[t[i] - 'a']--;
		i++;
	}
	if (s[i] || t[i])
		return (false);
	i = 0;
	while (i < 26)
	{
		if (counter[i++])
			return (false);
	}
	return (true);
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
	bool is_anagram = isAnagram("anagram", "nagaram");
	printf("%d\n", is_anagram);
}