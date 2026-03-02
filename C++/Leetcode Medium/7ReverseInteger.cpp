#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;
        if ((!isNeg && x < 10) || (isNeg && x > -10)) return x;

        string xString = to_string(x);
        string revXString(xString.rbegin(), xString.rend());
        if (revXString.back() == '-') revXString.pop_back();


        int lastNum = stoi(string(1, revXString.back()));
        revXString.pop_back();
        int revX = stoi(revXString); //revX is actually reverse of x / 10

        if (!isNeg) { //positive numbers
            if (revX < INT_MAX/10) return (revX * 10) + lastNum;
            else if (revX == INT_MAX/10) {
                return (INT_MAX % 10 <= lastNum) ? 0 : (revX * 10) + lastNum;
            }
            else return 0;
        } 
        else {
            if (revX < -1 * (INT_MIN/10)) return -1 * ((revX * 10) + lastNum);
            else if (revX == -1 * (INT_MIN/10)) return (INT_MIN % 10 >= lastNum) ? 0 : -1 * ((revX * 10) + lastNum);
            else return 0;
        }
    }
};