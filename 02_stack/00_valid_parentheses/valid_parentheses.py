class Solution:
    def isValid(self, s: str) -> bool:
        other = {
            ')': '(',
            ']': '[',
            '}': '{'
        }
        check = []
        for c in s:
            if c in "([{":
                check.insert(0, c)
            elif c in other:
                if len(check) == 0 or check[0] != other[c]:
                    return False
                else:
                    check.pop(0)
        return len(check) == 0


if __name__ == "__main__":
    solution = Solution()
    print(solution.isValid("]"))
        