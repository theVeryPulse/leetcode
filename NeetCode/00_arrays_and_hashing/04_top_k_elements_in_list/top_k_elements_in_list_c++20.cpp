#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ranges>

struct FrequencyAndNum
{
    int frequency;
    int num;
};

/**
 * @brief
 *
 * @param a
 * @param b
 * @return true
 * @note use `>` instead of `<` to achieve descending order.
 */
constexpr bool compare(FrequencyAndNum& a, FrequencyAndNum& b)
{
    return a.frequency > b.frequency;
}

class Solution
{
  public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> frequency_map;
        for (const auto& num : nums)
            ++frequency_map[num];

        std::vector<FrequencyAndNum> count_to_num;
        for (const auto& [num, frequency] : frequency_map) // structured binding
            count_to_num.push_back((FrequencyAndNum){frequency, num});

        std::ranges::sort(count_to_num, &compare);

        std::vector<int> answer;
        for (const auto& item : count_to_num | std::views::take(k)) // views and ranges
            answer.push_back(item.num);

        return answer;
    }
};