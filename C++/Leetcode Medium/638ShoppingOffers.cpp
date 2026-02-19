#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int helper(vector<vector<int>>& specials, vector<int>& needs, int i, unordered_map<long long, int>& mem) {
        int maxNeed = needs[0];
        int minNeed = needs[0];
        for (int need : needs) {
            maxNeed = max(maxNeed, need);
            minNeed = min(minNeed, need);
        }
        if (minNeed < 0) return 1000000;
        else if (maxNeed == 0) return 0;

        long long currHash = 0;
        for (int i = 0; i < needs.size(); ++i) {
            currHash *= 12;
            int currNeed = needs[i];
            currHash += currNeed;
        }
        currHash *= 12;
        currHash += i;
        if (mem.find(currHash) != mem.end()) return mem[currHash];


        int res = 1000000;

        //use special
        vector<int>& currSpecial = specials[i];
        for (int i = 0; i < currSpecial.size()-1; ++i) {
            needs[i] -= currSpecial[i];
            minNeed = min(minNeed, needs[i]);
        }
        res = min(res, currSpecial.back() + helper(specials, needs, i, mem));
        for (int i = 0; i < currSpecial.size()-1; ++i) {
            needs[i] += currSpecial[i];
        }

        //skip special
        if (i + 1 < specials.size()) res = min(res, helper(specials, needs, i+1, mem));   


        mem[currHash] = res;
        return res;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        for (int i = 0; i < price.size(); ++i) {
            vector<int> temp(price.size()+1, 0);
            temp[i] = 1;
            temp.back() = price[i];
            special.push_back(temp);
        }

        unordered_map<long long, int> map; //[hash, res]

        return helper(special, needs, 0, map);

    }
};