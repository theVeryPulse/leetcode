from typing import List


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if len(flowerbed) == 1:
            return n <= (1 if flowerbed[0] == 0 else 0)

        i, total = 0, 0
        while i < len(flowerbed):
            if i == 0:
                if flowerbed[i] == 0 and flowerbed[i+1] == 0:
                    i, total = i+1, total+1
            elif i == len(flowerbed) - 1:
                if flowerbed[i] == 0 and flowerbed[i-1] == 0:
                    i, total = i+1, total+1
            else:
                if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                    i, total = i+1, total+1
            i += 1
        return n <= total
