#https://leetcode.com/problems/time-based-key-value-store/description/
class TimeMap:
    #Hashmap, key:key,,,, value:[(timestamp, value)]
    def __init__(self):
        self.dictionary = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.dictionary[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        arr = self.dictionary[key]
        l, r = 0, len(arr)-1
        ret = ""
        while l <= r:
            m = (l + r) // 2
            if arr[m][0] <= timestamp:
                ret = arr[m][1]
            if timestamp < arr[m][0]:
                r = m-1
            else:
                l = m+1
        return ret

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)  