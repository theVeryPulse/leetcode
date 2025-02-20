from typing import List


class Solution:
    def count_bits_in_num(self, n: int) -> int:
        bit_count: int = 0
        for i in range(32):
            if n & (1 << i):
                bit_count += 1
            if (1 << i) > n:
                continue
        return bit_count

    def countBits(self, n: int) -> List[int]:
        bits = [self.count_bits_in_num(num) for num in range(n + 1)]
        return bits
