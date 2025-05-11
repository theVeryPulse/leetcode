from typing import List


class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def divides(short: str, long: str) -> bool:
            return short * (len(long) // len(short)) == long

        divisor_len = 0
        len_max = min(len(str1), len(str2))
        for i in range(len_max):
            if str1[i] == str2[i]:
                divisor_len += 1
            else:
                break
        while divisor_len > 0:
            if len(str1) % divisor_len == 0 and len(str2) % divisor_len == 0:
                canditate = str1[:divisor_len]
                if divides(canditate, str1) and divides(canditate, str2):
                    return str1[0:divisor_len]
            divisor_len -= 1
        return ""


if __name__ == "__main__":
    solution = Solution()
    print(solution.gcdOfStrings("ABC", "ABCDEF"))
