#https://leetcode.com/problems/time-needed-to-buy-tickets/description/
class Solution:
    def timeRequiredToBuy(self, tickets: List[int], k: int) -> int:
        counter = 0
        idx = 0
        while True:
            if idx == len(tickets):
                idx = 0
            tickets[idx] -= 1
            counter += 1
            if tickets[idx] == 0:
                if idx == k:
                    return counter
                if k > idx:
                    k -= 1
                tickets.pop(idx)
                idx -= 1
            idx += 1