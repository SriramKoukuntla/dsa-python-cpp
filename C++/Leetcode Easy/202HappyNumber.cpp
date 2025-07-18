#include <unordered_set>
#include <cmath> 
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        return helper(n, seen);
    }

private:
    bool helper(int num, unordered_set<int>& seen){
        if (num == 1) return true;
        if (seen.find(num) != seen.end()) return false;
        seen.insert(num);
        int newNum = 0;
        while (num > 0){
            newNum += pow(num % 10, 2);
            num /= 10;
        }
        return helper(newNum, seen);
    }
};