class Solution:
    def reverseBits(self, n: int) -> int:
        reversed: int = 0
        for i in range(32):
            reversed += 1 if n & (1 << i) else 0
            if i != 31:
                reversed <<= 1
        return reversed