class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = [a + b for a, b in zip(word1, word2)]
        return "".join(merged) + word1[len(word2):] + word2[len(word1):]


if __name__ == "__main__":
    solution = Solution()
    ans = (solution.mergeAlternately("abc", "ABC"))
    print(ans)
