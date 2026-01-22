class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i : nums) set.insert(i);
        int res = 0;
        for (int i : set){
            if (set.find(i-1) != set.end()) continue;
            int curr = i;
            int temp = 0;
            while (set.find(curr) != set.end()) {
                ++curr;
                ++temp;
            }
            res = max(res, temp);
        }
        return res;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int i : nums) set.insert(i);
        int res = 0;
        for (int i : set) {
            if (set.find(i-1) == set.end()){
                int length = 0;
                while (set.find(i + length) != set.end()) ++length;
                res = max(res, length);
            }
        }
        return res;
    }
};