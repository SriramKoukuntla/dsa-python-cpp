#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> res;
    unordered_map<int, unordered_set<int>> freqMap;
    for (vector<int> query : queries) freqMap[0].insert(query[1]);
    unordered_map<int, int> map;
    for (int i = 0; i < queries.size(); ++i) {
        vector<int> currQuery = queries[i];
        int operation = currQuery[0];
        int dataElement = currQuery[1];
        if (operation == 1) {
            int oldFreq = map[dataElement]++;
            freqMap[oldFreq].erase(dataElement);
            freqMap[oldFreq+1].insert(dataElement);
        }
        else if (operation == 2) {
            int oldFreq = map[dataElement];
            if (oldFreq == 0) continue;
            --map[dataElement];
            freqMap[oldFreq].erase(dataElement);
            freqMap[oldFreq-1].insert(dataElement);
        }
        else if (operation == 3) {
            if (freqMap[dataElement].empty()) res.push_back(0);
            else res.push_back(1);
        }
    }
    return res;
}