public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int begin = 0;
        int end = 0;
        int longest = 0;
        HashSet<char> charTrack = new HashSet<char>();
        while (end < s.Length)
        {
            while (charTrack.Contains(s[end]))
            {
                charTrack.Remove(s[begin]);
                begin++;
            }
            charTrack.Add(s[end]);
            end++;
            longest = Math.Max(longest, end - begin);
        }
        return longest;
    }

    static void Main()
    {
        Solution sln = new Solution();
        string test;

        test = "aab";
        if (sln.LengthOfLongestSubstring(test) == 2)
            Console.WriteLine("OK");

        test = "nfpdmpi";
        if (sln.LengthOfLongestSubstring(test) == 5)
            Console.WriteLine("OK");

        test = "abc";
        if (sln.LengthOfLongestSubstring(test) == 3)
            Console.WriteLine("OK");

        test = "tmmzuxt";
        if (sln.LengthOfLongestSubstring(test) == 5)
            Console.WriteLine("OK");
    }
}