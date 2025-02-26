/**
 * @brief Given an integer array nums, return true if any value appears at least
 *        twice in the array, and return false if every element is distinct.
 *
 * @ref   https://leetcode.com/problems/contains-duplicate/description/
 */

 #include <vector>
 #include <unordered_set>
 
 class Solution
 {
   public:
     bool containsDuplicate(std::vector<int>& nums)
     {
         std::unordered_set<int> track;
         for (const int& num : nums) {
             if (track.contains(num))
                 return true;
             else
                 track.insert(num);
         }
         return false;
     }
 };
 
 #include <iostream>
 
 int main()
 {
     // std::vector<int> vec = {1, 1, 3, 3, 4, 3, 2, 4, 2};
     std::vector<int> vec = {1, 2, 3, 4, 5};
 
     Solution solution;
     std::cout << "Contains duplicate: " << solution.containsDuplicate(vec)
               << "\n";
 }
 