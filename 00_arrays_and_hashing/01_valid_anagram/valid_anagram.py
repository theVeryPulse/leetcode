class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        track = dict()
        for letter in "abcdefghijklmnopqrstuvwxyz":
            track[letter] = 0
        for letter in s:
            track[letter] += 1
        for letter in t:
            track[letter] -= 1
        for letter_count in track:
            if track[letter_count] != 0:
                return False
        return True


def test():
    solution = Solution()
    solution.isAnagram("rat", "car")


if __name__ == "__main__":
    test()