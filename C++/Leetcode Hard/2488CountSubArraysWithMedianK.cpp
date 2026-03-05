#include <vector>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        //Transform nums to elements with only -1, 0, 1
        for (int& num : nums) num = (num < k) ? -1 : (num > k) ? 1 : 0;

        //Create prefixSum
        vector<int> prefixSum(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) prefixSum[i] = (i==0) ? nums[i] : nums[i] + prefixSum[i-1];

        //Find index of K
        int idxK = -1;
        for (int i = 0; i < nums.size(); ++i) if (nums[i] == 0) idxK = i;

        //store number of occurrences of each prefixSum after J
        unordered_map<int, int> prefixSumFreqKOnwards;
        for (int i = idxK; i < nums.size(); ++i) ++prefixSumFreqKOnwards[prefixSum[i]];

        //Iterations
        //sum(i, j) is sum of subset of elements from i to j
        //Iterate over for every i that is less than or equal to idxK for every j that is greater than or equal to idkK
        int res = 0;
        for (int i = 0; i <= idxK; ++i) {
            int prefixSumI = (i-1 < 0) ? 0 : prefixSum[i-1];
            int occurrances = prefixSumFreqKOnwards[prefixSumI] + prefixSumFreqKOnwards[prefixSumI+1];
            res += occurrances;
        }
        return res; 
    }
};

class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        //Transform array from nums-> to only having elements of -1, 0, 1
        for (int& num : nums) num = (num < k) ? -1 : (num > k) ? 1 : 0;

        //PrefixSum
        vector<int> prefixSum;
        for (int i = 0; i < nums.size(); ++i) prefixSum.push_back((i==0) ? nums[i] : nums[i] + prefixSum[i-1]);

        //find k
        int kIdx = -1;
        unordered_map<int, int> prekIdxPrefixSumOcurrences;
        ++prekIdxPrefixSumOcurrences[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {kIdx = i; break;}
            else ++prekIdxPrefixSumOcurrences[prefixSum[i]];
        }

        //Single iteration
        int res = 0;
        for (int i = kIdx; i < nums.size(); ++i) {
            int currPrefixSum = prefixSum[i];
            int target1 = 0;
            int target2 = 1;
            res += (prekIdxPrefixSumOcurrences[currPrefixSum-target1] + prekIdxPrefixSumOcurrences[currPrefixSum-target2]);
        }

        return res;
    }
};

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        for (int& num : nums) {
            if (num < k) num = -1;
            else if (num > k) num = 1;
            else num = 0;
        }

        unordered_map<int, int> map;
        ++map[0];
        vector<int> prefixSum(nums.size(), 0);
        bool kSeen = false;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i] = (i == 0) ? nums[i] : prefixSum[i-1] + nums[i];
            if (nums[i] == 0) kSeen = true;
            if (!kSeen) ++map[prefixSum[i]];
            else {
                int target1 = prefixSum[i];
                int target2 = prefixSum[i]-1;
                res += (map[target1] + map[target2]);
            }
        }
        return res; 
    }
};