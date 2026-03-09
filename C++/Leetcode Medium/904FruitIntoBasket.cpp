#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int l = 0;
        unordered_map<int, int> fruitsFreq; //counting frequency of fruit inside window
        for (int r = 0; r < fruits.size(); ++r) {
            ++fruitsFreq[fruits[r]];
            while (fruitsFreq.size() > 2) {
                if(--fruitsFreq[fruits[l]] == 0) fruitsFreq.erase(fruits[l]);
                ++l;
            }
            res = max(res, r-l+1);
        }
        return res; 
    }
};