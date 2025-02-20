int hammingWeight(int n)
{
    int one_bit_count = 0;
    for (int i = 0; i < 31; ++i)
    {
        if (n & (1 << i))
            one_bit_count += 1;
    }
    return one_bit_count;
}