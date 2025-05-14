from typing import List, Callable


class Solution:
    operations = {
        "+": lambda a, b: a + b,
        "-": lambda a, b: a - b,
        "*": lambda a, b: a * b,
        "/": lambda a, b: int(a / b)
    }

    def evalRPN(self, tokens: List[str]) -> int:
        track = list()
        for token in tokens:
            if token in "+-*/":
                second = track.pop()
                first = track.pop()
                track.append(self.operations[token](first, second))
            else:
                track.append(int(token))
        return track[0]


if __name__ == "__main__":
    notation = ["2", "1", "+", "3", "*"]
    notation = ["4", "13", "5", "/", "+"]
    notation = ["10", "6", "9", "3", "+", "-11",
                "*", "/", "*", "17", "+", "5", "+"]
    solution = Solution()
    print(solution.evalRPN(notation))
