import collections

class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        ans = collections.defaultdict(list) # Each key maps to a list of strings
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord("a")] += 1
            ans[tuple(count)].append(s) # tuple is ordered, unchangeable, and 
        return ans.values()             # allows duplicates
