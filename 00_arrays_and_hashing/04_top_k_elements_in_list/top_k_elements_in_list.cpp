#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

struct CountNum
{
    int count;
    int num;
};

/**
 * @brief Returns `true` if first argument is less
 *
 * @return true
 * @return false
 */
bool compareCount(const CountNum& l, const CountNum& r)
{
    return l.count < r.count;
}

class Solution
{
  public:
    typedef std::map<int, int> Map;

    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        Map num_to_count;
        for (std::vector<int>::const_iterator num = nums.begin();
             num != nums.end(); ++num)
            ++(num_to_count[*num]);

        std::vector<CountNum> counts_and_nums(num_to_count.size());
        for (Map::const_iterator num_count = num_to_count.begin();
             num_count != num_to_count.end(); ++num_count)
        {
            counts_and_nums.push_back((CountNum){.count = num_count->second,
                                                 .num = num_count->first});
        }
        std::sort(counts_and_nums.begin(), counts_and_nums.end(),
                  &compareCount);

        std::vector<int> solution;
        for (std::vector<CountNum>::const_reverse_iterator count_num =
                 counts_and_nums.rbegin();
             count_num != counts_and_nums.rend(); ++count_num)
        {
            solution.push_back(count_num->num);
            --k;
            if (k == 0)
                break;
        }
        return solution;
    }
};

int main()
{
    Solution         solution;
    std::vector<int> vec;

    /* vec.push_back(1);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3); */

    vec.push_back(-1);
    vec.push_back(-1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);

    int              k = 2;
    std::vector<int> top_k = solution.topKFrequent(vec, k);
    for (std::vector<int>::const_iterator num = top_k.begin();
         num != top_k.end(); ++num)
        std::cout << *num << "\n";
}
