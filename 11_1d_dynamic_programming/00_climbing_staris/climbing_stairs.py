class Solution:
    def climbStairs(self, n: int) -> int:
        prev = 1
        curr = 1
        for _ in range(n - 1):
            next = prev + curr
            prev = curr
            curr = next
        return curr
            
            

