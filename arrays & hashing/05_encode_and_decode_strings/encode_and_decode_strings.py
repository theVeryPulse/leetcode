class Solution:

    def encode(self, strs: list[str]) -> str:
        encoded = ""
        for str in strs:
            encoded += str
            encoded += "#~"
        return encoded

    def decode(self, s: str) -> list[str]:
        decoded = []
        begin = 0
        for index, c in enumerate(s):
            if s[index:index+2] == "#~":
                decoded.append(s[begin:index])
                begin = index + 2
        return decoded


def test():
    solution = Solution()
    encoded: str = solution.encode(["hello", "world"])
    print(encoded)
    decoded: list[str] = solution.decode(encoded)
    for string in decoded:
        print(string)


if __name__ == "__main__":
    test()