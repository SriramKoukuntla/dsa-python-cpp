#include <vector>
using namespace std;
class NumArray {
public:
    vector<int> numbers;
    vector<int> preFixSum;
    NumArray(vector<int>& nums) {
        numbers = nums;
        preFixSum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            preFixSum.push_back(preFixSum[i-1] + numbers[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return preFixSum[right];
        return preFixSum[right]-preFixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */