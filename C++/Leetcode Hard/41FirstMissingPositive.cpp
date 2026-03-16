#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int& currNum = nums[i];
            if (currNum <= 0 || currNum > nums.size() || (currNum-1 != i && nums[currNum-1] == currNum)) currNum = -1;
            else if (currNum == i+1) continue;
            else {swap(currNum, nums[currNum-1]); --i;}
        }
        for (int i = 0; i < nums.size(); ++i) if (nums[i] == -1) return i+1;
        return nums.size()+1;
    }
};
//
//[4, 5, 6] 
//[1,2,0]
//[2,1,0]
//[0,1,2]
//[7,8,9,11,12]
//First traversal, replace any negative numbers or 0 or values that are greater than nums.size() with -1
//other wise, swap with element at index, if duplicate, turn into -1
//second travesal return first index with -1 with index + 1