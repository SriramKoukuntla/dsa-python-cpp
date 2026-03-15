#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& balls) {
        //Count frequency of each ball
        unordered_map<int, int> freq;
        for (int ball : balls) ++freq[ball];

        //initialize ranges
        int l = 1;
        int r = 0;
        for (auto [ballType, currFreq] : freq) r = max(r, currFreq);

        //Linear Search
        int size = 0;
        for (int currSize = l; currSize <= r; ++currSize) {
            int valid = true;
            for (auto [ballType, currFreq] : freq) {
                int numBoxes = currFreq / currSize;
                int remainder = currFreq % currSize;
                if (remainder > numBoxes) valid = false;
                if (!valid) break;
            }
            if (valid) size = currSize+1;
        }        

        //Calculate res aka number of boxes
        int res = 0;
        for (auto [ballType, currFreq] : freq) {
            float temp1 = 1.0f * currFreq / size;
            int temp  = ceil(temp1);
            res += temp;
        }
        
        return res;
    }
};