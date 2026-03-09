#include <list>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        list<pair<int, int>> queue; //Fresh orange that is to be turned into a rotten orange or is an invalid space such as rotten or empty
        int numOfFreshOranges = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    queue.push_back({i, j});
                    grid[i][j] = 1;
                }
                if (grid[i][j] == 1) ++numOfFreshOranges;
            }
        }
        if (numOfFreshOranges == 0) return 0;

        int time = -1;
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                auto [currI, currJ] = queue.front();
                queue.pop_front();
                if (currI < 0 || currJ < 0 || currI >= grid.size() || currJ >= grid[0].size()) continue;
                if (grid[currI][currJ] != 1) continue;
                grid[currI][currJ] = 2;
                --numOfFreshOranges;
                queue.push_back({currI+1, currJ});
                queue.push_back({currI-1, currJ});
                queue.push_back({currI, currJ+1});
                queue.push_back({currI, currJ-1});
            }
            ++time;
            if (numOfFreshOranges == 0) return time;
        }
        return -1;
    }
};