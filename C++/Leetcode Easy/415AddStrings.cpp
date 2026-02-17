#include <string>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1Idx = num1.size()-1;
        int num2Idx = num2.size()-1;
        int OneOverFlow = 0;
        string revRes;
        while (num1Idx >= 0 || num2Idx >= 0 || OneOverFlow) {
            int val = 0;
            if (num1Idx >= 0) val += (num1[num1Idx--]-'0');
            if (num2Idx >= 0) val += (num2[num2Idx--]-'0');
            if (OneOverFlow) {val += 1; OneOverFlow = 0;}
            if (val >= 10) {
                OneOverFlow = 1;
                val %= 10;
            }
            revRes += to_string(val);

        }
        string res(revRes.rbegin(), revRes.rend());
        return res;
    }
};