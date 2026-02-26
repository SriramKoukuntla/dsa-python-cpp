//Manacher's Algorithm is used to find the longest palindrome in a string in O(n) time.
//any index in s can be mapped to sPrime f(i) = 2i+1
//If you are in a larger palindrome, then the radius of the largest palindrome which centers around i is min(radius[mirrorI], r-i)
//Radius represents how many characters beyond the center match 
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        //Preprocessing string s
        string sPrime;
        for (int i = 0; i < s.size(); ++i) sPrime += (i == 0) ? "*" + string(1, s[i]) + "*" : string(1, s[i]) + "*";

        //Tracking information initialization
        vector<int> radius(sPrime.size(), 0);
        int c = 0;
        int r = 0;
        int maxRadius = 0;
        int largestPalindromeCenter = 0;

        //Core algorithm
        for (int i = 0; i < sPrime.size(); ++i) {
            //If we are in a larger palindrome
            int mirrorIndex = c-(i-c);
            if (i < r) radius[i] = min(radius[mirrorIndex], r-i);

            //Keep checking if palindrome beyond current radius
            while (i-radius[i]-1 >=0 && i+radius[i]+1 < sPrime.size() && sPrime[i-radius[i]-1] == sPrime[i+radius[i]+1]) ++radius[i];

            //update c and r
            if (i + radius[i] > r) {
                c = i;
                r = i + radius[i];
            }

            //Update our res tracking information
            if (radius[i] > maxRadius) {
                maxRadius = radius[i];
                largestPalindromeCenter = i;
            }
        }
        int start = (largestPalindromeCenter - maxRadius) / 2;
        return s.substr(start, maxRadius);
    }
};