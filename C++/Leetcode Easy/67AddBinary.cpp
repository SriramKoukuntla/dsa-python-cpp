#include <list>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        list<char> resList;
        int size = min(a.size(), b.size());
        int carry = 0;
        for (int i = 0; i < size; ++i) {
            int firstBit = a[a.size()-1-i] == '1' ? 1 : 0;
            int secondBit = b[b.size()-1-i] == '1' ? 1 : 0;
            int sum = carry + firstBit + secondBit; 
            carry = sum / 2;
            if (sum % 2 == 0) resList.push_front('0');
            else resList.push_front('1');
        }

        //invariant that a.size() is >= b.size()
        if (b.size() > a.size()) swap(a, b);
        for (int i = 0; i < a.size()-size; ++i) {
            int firstBit = a[a.size()-1-size-i] == '1' ? 1 : 0;
            int sum = carry + firstBit;
            carry = sum / 2;
            if (sum % 2 == 0) resList.push_front('0');
            else resList.push_front('1');
        }
        if (carry == 1) resList.push_front('1');

        string res;
        for (char c : resList) res += c;
        return res;
    }
};