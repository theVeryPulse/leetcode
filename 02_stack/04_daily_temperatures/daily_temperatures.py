from typing import List

# Input: temperatures = [73,74,75,71,69,72,76,73]
# Output: [1,1,4,2,1,1,0,0]


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        index_to_solve = list()
        for i, temp in enumerate(temperatures):
            while index_to_solve and temp > temperatures[index_to_solve[-1]]:
                answer[index_to_solve[-1]] = i - index_to_solve[-1]
                index_to_solve.pop()
            else:
                index_to_solve.append(i)
        return answer


if __name__ == "__main__":
    solution = Solution()
    print(solution.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]))
    print(solution.dailyTemperatures([80, 34, 80, 80, 80, 34, 34, 34, 34, 34]))
