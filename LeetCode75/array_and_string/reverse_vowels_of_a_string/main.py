class Solution:
    def reverseVowels(self, s: str) -> str:
        VOWELS = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}
        left = 0
        right = len(s) - 1
        reversed = list(s)
        while (left < right):
            while reversed[left] not in VOWELS and left < right:
                left += 1
            while reversed[right] not in VOWELS and left < right:
                right -= 1
            if (reversed[left] in VOWELS and reversed[right] in VOWELS):
                reversed[left], reversed[right] = reversed[right], reversed[left]
            left += 1
            right -= 1
        return "".join(reversed)


if __name__ == "__main__":
    sln = Solution()
    result = sln.reverseVowels("leetcode")
    print(result)
