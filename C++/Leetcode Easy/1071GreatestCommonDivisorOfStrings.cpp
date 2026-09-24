#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        unordered_set<string> set1 = findDivisors(str1);
        unordered_set<string> set2 = findDivisors(str2);
        string res = "";
        for (const string& string1 : set1) {
            if (set2.find(string1) != set2.end() && string1.size() > res.size()) res = string1; 
        }
        return res;
    }
    unordered_set<string> findDivisors(string str) {
        unordered_set<string> res;
        for (int i = 1; i <= str.size(); ++i) {
            if (str.size() % i != 0) continue;
            int length = str.size() / i;
            string firstSegment = str.substr(0, length);
            bool divisible = true;
            for (int j = length; j < str.size(); j += length) {
                if (firstSegment != str.substr(j, length)) {
                    divisible = false;
                    break;
                }
                
            }
            if (divisible) res.insert(firstSegment);
        }
        return res; 
    }
};071