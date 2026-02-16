#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_set<int> allBoxes;
        unordered_set<int> allKeys;
        list<int> queue; //If it's open or we have the key it goes here to be processed
        for (int box : initialBoxes) if (status[box]) queue.push_back(box); else allBoxes.insert(box);

        int res = 0;
        while (!queue.empty()) {
            int currBox = queue.front();
            queue.pop_front();
            res += candies[currBox];
            for (int key : keys[currBox]) {
                if (allBoxes.find(key) != allBoxes.end()) {
                    queue.push_back(key);
                    allBoxes.erase(key);
                } 
                else allKeys.insert(key);
            }

            for (int containedBox : containedBoxes[currBox]) {
                if (status[containedBox]) queue.push_back(containedBox);
                else if (allKeys.find(containedBox) != allKeys.end()) {
                    queue.push_back(containedBox);
                    allKeys.erase(containedBox);
                }
                else allBoxes.insert(containedBox);
            }
        }

        return res;
    }
};