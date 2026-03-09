#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //Insert values [1, n^2] into set
        unordered_set<int> set;
        for (int i = 1; i <= pow(grid.size(), 2); ++i) set.insert(i);
        //Remove every value in grid to find a and b
        int a = -1;
        int b = -1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (set.find(grid[i][j]) == set.end()) a = grid[i][j];
                set.erase(grid[i][j]);
            }
        }
        b = *set.begin();
        return {a, b};
    }
};