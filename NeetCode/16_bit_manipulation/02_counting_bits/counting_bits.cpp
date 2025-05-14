#include <vector>

using namespace std;

class Solution
{
  public:
    vector<int> countBits(int n)
    {
        vector<int> bits(n + 1);
        for (int i = 0; i < n + 1; ++i)
            bits[i] = count_bits_in_num(i);
        return bits;
    }
  private:
    int count_bits_in_num(int num)
    {
        int bits_count = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (num & (1 << i))
                bits_count++;
            if ((1 << i) > num)
                return bits_count;
        }
        return bits_count;
    }
};