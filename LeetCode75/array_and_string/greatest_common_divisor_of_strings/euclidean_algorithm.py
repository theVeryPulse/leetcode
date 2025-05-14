class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1:
            return ""
        big = max(len(str1), len(str2))
        small = min(len(str1), len(str2))
        while small != 0:
            small_tmp = small
            small = big % small
            big = small_tmp
        divisor_len = big
        return str1[:divisor_len]


if __name__ == "__main__":
    solution = Solution()
    print(solution.gcdOfStrings("ABAB", "ABABAB"))
