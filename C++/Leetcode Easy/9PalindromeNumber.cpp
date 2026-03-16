#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        //Find Size
        int size = 0;
        int tempX = x;
        while (tempX != 0) {++size; tempX /= 10;}
        
        //Create reversed second half
        int reversedSecondHalf = 0;
        for (int i = 0; i < size/2; ++i) {
            reversedSecondHalf *= 10;
            reversedSecondHalf += (x % 10);
            x /= 10;
        }
        if (size % 2 == 1) x /= 10;

        while (x != 0 || reversedSecondHalf != 0) {
            if (x % 10 != reversedSecondHalf % 10) return false;
            x /= 10;
            reversedSecondHalf /= 10;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        string xString = to_string(x);
        for (int i = 0; i < xString.size()/2; ++i) if (xString[i] != xString[xString.size()-1-i]) return false;
        return true;
    }
};
//turn to string (xString)
//iterate for xString.size()/2 times and see if xString[i] == xString[xString.size()-1-i]. if not return false;
//return true