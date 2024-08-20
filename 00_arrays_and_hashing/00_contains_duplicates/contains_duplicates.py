# Topics: Array, Hash Table, Sorting

class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        checked_numbers = set()
        for number in nums:
            if number not in checked_numbers:
                checked_numbers.add(number)
            else:
                return True
        return False


def main():
    solution = Solution()
    numbers = [1, 2, 3, 4, 5]
    contains_duplicates = solution.containsDuplicate(numbers)
    print(contains_duplicates)


if __name__ == "__main__":
    main()
