# Group Anagrams
## Description
Given an array of strings `strs`, group the anagrams together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

URL: https://leetcode.com/problems/group-anagrams/description/

## Notes
The key of solving this problem is to generate the same key for strings that are anagrams. The best medium to generate the key is an array of integers counting the occurrences of each letter. In Python, we can do this by converting the `list[int]` into a `tuple`, which can be used as the key to a `dict` (map). In C++, we can do this by defining a helper class and providing the `operator<` for this class. Also in C++, we can convert an array of integers to a `std::string`. In this case, we can use a symbol (comma for example) to delimit the numbers, we than have something like `(std::string)"0,0,1,...,1,3"` which we can use as key to a `std::map`