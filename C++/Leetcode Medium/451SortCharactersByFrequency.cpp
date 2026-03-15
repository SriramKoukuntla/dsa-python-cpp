#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        //Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) ++freq[c];

        //Sort
        vector<tuple<int, char>> sortedChars;
        for (auto [letter, frequency] : freq) sortedChars.push_back({frequency, letter});
        sort(sortedChars.begin(), sortedChars.end(), greater<tuple<int, char>>()); //Highest frequency to lowest

        //Create res string
        string res = "";
        for (auto [frequency, letter] : sortedChars) res += string(frequency, letter);
        return res; 
    }
};
//Count frequency of each character
//Sort by ascending
//Add strings to res based on their count