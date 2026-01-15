#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size()-1;
        int sum = numbers[begin] + numbers[end];
        while (sum != target){
            if (sum > target) --end;
            else ++begin;
            sum = numbers[begin] + numbers[end];
        }
        return {begin+1, end+1};
    }
};