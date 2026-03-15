#include <set>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        //Count frequency
        unordered_map<char, int> freq;
        for (char c : s) ++freq[c];

        //Put frequencies into max heap
        set<tuple<int, char>> rbt;
        for (auto [letter, frequency] : freq) rbt.insert({frequency, letter});


        //Generate String
        string res = "";
        while (!rbt.empty()) {
            auto [currFreq, currLetter] = *rbt.rbegin();
            rbt.erase(prev(rbt.end()));
            if (res.size() == 0 || res.back() != currLetter) res += currLetter;
            else return "";

            if (!rbt.empty()) {
                auto [currFreq2, currLetter2] = *rbt.rbegin();
                rbt.erase(prev(rbt.end()));
                res += currLetter2;
                if (currFreq-1 > 0) rbt.insert({currFreq-1, currLetter});
                if (currFreq2-1 > 0) rbt.insert({currFreq2-1, currLetter2});
            }
            else if (currFreq-1 > 0) rbt.insert({currFreq-1, currLetter});
        }
        return res;
    }
};

#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        //Count frequency
        unordered_map<char, int> freq;
        for (char c : s) ++freq[c];

        //Put frequencies into max heap
        priority_queue<pair<int, char>> pq;
        for (auto [letter, frequency] : freq) pq.push({frequency, letter});

        //Generate String
        string res = "";
        while (!pq.empty()) {
            auto [currFreq, currLetter] = pq.top();
            pq.pop();
            if (res.size() == 0 || res.back() != currLetter) res += currLetter;
            else return "";

            if (!pq.empty()) {
                auto [currFreq2, currLetter2] = pq.top();
                pq.pop();
                res += currLetter2;
                if (currFreq-1 > 0) pq.push({currFreq-1, currLetter});
                if (currFreq2-1 > 0) pq.push({currFreq2-1, currLetter2});
            }
            else if (currFreq-1 > 0) pq.push({currFreq-1, currLetter});
        }
        return res;
    }
};