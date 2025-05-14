#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
  public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        const int highest_count =
            *(std::max_element(candies.begin(), candies.end()));
        std::vector<bool> track;
        track.reserve(candies.size());
        for (int candy_count : candies)
            track.emplace_back(candy_count + extraCandies >= highest_count);
        return track;
    }
};