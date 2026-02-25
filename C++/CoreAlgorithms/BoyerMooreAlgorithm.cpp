//Given a list of numbers, Boyer Moore Majority Vote Algorithm can determine the element that occurs most frequently in O(n)
#include <vector>
using namespace std;
int BoyerMooreAlgorithm(vector<int> nums) {
    int count = 1;
    int currNum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            count = 1;
            currNum = nums[i];
        }
        else if (nums[i] != currNum) {
            --count;
        }
        else if (nums[i] == currNum) {
            ++count;
        }
    }

    //check to see if currNum is majority present in nums
    count = 0;
    for (int num : nums) if (num == currNum) ++count;

    return (count > nums.size()/2) ? currNum : -1;
}