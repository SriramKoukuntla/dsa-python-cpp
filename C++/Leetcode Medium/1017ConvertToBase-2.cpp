#include <string>
using namespace std;
class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        string res = "";
        while (N != 0) {
            int remainder = N % -2; //remainder has to always be [0, k-1] where k is base
            N /= -2;
            if (remainder < 0) {
                remainder += 2; //n % -2 is congruent to n - k % 2;
                N += 1; 
                //OldNumber = k * NewNumber + r
                //if r < 0 then r is now r'. r' = r - k
                //OldNumber = k * NewNumber' + r'
                //k * NewNumber + r == k * NewNumber' + r'
                //k * NewNumber + r == k * NewNumber' + r - k
                //k * NewNumber == k * NewNumber' - k
                //NewNumber == NewNumber' - 1
                //NewNumber' = NewNumber + 1
            }
            res = to_string(remainder) + res;
        }
        return res;
    }
};