class Solution {
public:
    string frequencySort(string s) {
        //Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) ++freq[c];

        //Sort
        vector<vector<char>> sortedChars(s.size()+1); //index = frequency of characters
        for (auto [letter, frequency] : freq) sortedChars[frequency].push_back(letter);

        //Create res string
        string res = "";
        for (int i = sortedChars.size()-1; i >= 0; --i) for (char letter : sortedChars[i]) res += string(i, letter);
        return res; 
    }
};
//Count frequency of each character
//Sort by ascending
//Add strings to res based on their count

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
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