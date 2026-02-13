#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        //Create inverse adjacency list
        unordered_map<string, string> smallToBig;
        for (vector<string>& reg : regions) for (int i = 1; i < reg.size(); ++i) smallToBig[reg[i]] = reg[0];

        //Create region1ToRootPath
        unordered_set<string> region1ToRootPath;
        for (string cur = region1; ; cur = smallToBig[cur]) {
            region1ToRootPath.insert(cur);
            if (!smallToBig.count(cur)) break;
        }

        //Check if node on the path to root from region2 is in region1 to root path
        string curr = region2;
        while (region1ToRootPath.find(curr) == region1ToRootPath.end()) curr = smallToBig[curr];
        return curr;
    }
};