#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res;
        
        for (int i = num2.size()-1; i >= 0; --i) {
            string tempRes = singleMultiple(num1, num2[i]);
            res = addition(res, tempRes);
            num1 = num1 + "0";
        }
        return res; 
    }

private:
    string singleMultiple(string num1, char num2) {
        string revRes;
        int carry = 0;
        int num2AsNum = num2 - '0';
        for (int i = num1.size()-1; i >= 0; --i) {
            char currChar = num1[i];
            int currNum = currChar - '0';
            int product = currNum * num2AsNum + carry;
            revRes += to_string(product % 10);
            carry = product / 10;
        }
        if (carry != 0) revRes += to_string(carry);
        reverse(revRes.begin(), revRes.end());
        return revRes;
    }
    string addition(string num1, string num2) {
        string revRes;
        int index1 = num1.size()-1;
        int index2 = num2.size()-1;
        int carry = 0;
        while (index1 >= 0 || index2 >= 0 || carry != 0) {
            int val1 = index1 >= 0 ? num1[index1]-'0' : 0;
            int val2 = index2 >= 0 ? num2[index2]-'0' : 0;
            int sum = val1 + val2 + carry;
            revRes += to_string(sum%10);
            carry = sum/10;
            --index1;
            --index2;
        }
        reverse(revRes.begin(), revRes.end());
        return revRes;
    }
};