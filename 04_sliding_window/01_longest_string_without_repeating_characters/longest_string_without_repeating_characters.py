class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        begin: int = 0
        end: int = 0
        char_track = set()
        longest: int = 0
        while end < len(s):
            # Skip all letters until duplicate is erased as well
            while s[end] in char_track:
                char_track.remove(s[begin])
                begin += 1
            char_track.add(s[end])
            end += 1
            longest = max(longest, end - begin)
        return longest
