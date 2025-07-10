class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        slow, fast = 1, max(piles)
        res = fast
        while slow <= fast:
            k = (slow + fast)//2
            t = 0
            for pile in piles:
                t += math.ceil(pile/2)
            if t <= h:
                res = min(res, k)
                fast = k - 1
            else:
                slow = k + 1
        return res