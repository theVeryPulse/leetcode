#include <inttypes.h>

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        int reversed = 0;
        for (int i = 0; i < 32; ++i)
        {
            reversed += (n & (1 << i)) ? 1 : 0;
            if (i != 31)
                reversed <<= 1;
        }
        return reversed;
    }
};