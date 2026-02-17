#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool layerBuilder(string& bottom, string& curr, int i,  unordered_map<string, vector<char>>& allowedSet, unordered_map<string, bool>& mem) {
        if (curr.size() == bottom.size()-1) return helper(curr, allowedSet, mem);
        string temp = bottom.substr(i, 2);
        for (char c : allowedSet[temp]) {
            curr.push_back(c);
            if (layerBuilder(bottom, curr, i+1, allowedSet, mem)) return true;
            curr.pop_back();
        }
        return false;
    }

    bool helper(string& bottom, unordered_map<string, vector<char>>& allowedSet, unordered_map<string, bool>& mem) {
        if (mem.find(bottom) != mem.end()) return mem[bottom];
        if (bottom.size() == 1) return true;

        string temp;
        bool res = layerBuilder(bottom, temp, 0, allowedSet, mem);

        mem[bottom] = res;
        return res;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> allowedSet;
        for (string& pattern : allowed) allowedSet[pattern.substr(0, 2)].push_back(pattern[2]);
        unordered_map<string, bool> mem;
        return helper(bottom, allowedSet, mem);
        return true;
    }
};