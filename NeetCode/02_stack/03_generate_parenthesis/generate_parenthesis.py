from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = list()
        solutions = list()

        def get_candidates(open: int, close: int) -> List[str]:
            candidates = []
            if (open < n):
                candidates.append("(")
            if (close < open):
                candidates.append(")")
            return candidates

        def backtrack(open: int, close: int):
            if open == close == n:
                solutions.append("".join(ans))
            for candidate in get_candidates(open, close):
                ans.append(candidate)
                backtrack(open + 1 if candidate == "(" else open,
                          close + 1 if candidate == ")" else close)
                ans.pop()

        backtrack(0, 0)
        return solutions


if __name__ == "__main__":
    solution = Solution()
    print(solution.generateParenthesis(3))
