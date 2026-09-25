#include <bits/stdc++.h>
using namespace std;
class DetectSquares {
public:
    vector<vector<int>> COUNT;
    unordered_map<int, unordered_set<int>> up; //give x axis coordinate, get every y
    DetectSquares() {
        COUNT = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        COUNT[point[0]][point[1]]++;
        up[point[0]].insert(point[1]);
    }
    
    int count(vector<int> point) {
        int res = 0;
        int ogX = point[0];
        int ogY = point[1];
        for (int y : up[ogX]) {
            if (y == ogY) continue;

            int diff = y - ogY;
            int absDiff = abs(diff);
            //check left for how many left squares
            if (ogX-absDiff >= 0) res += (COUNT[ogX][ogY + diff] * COUNT[ogX-absDiff][ogY] * COUNT[ogX-absDiff][ogY + diff]);
            if (ogX+absDiff <= 1000) res += (COUNT[ogX][ogY + diff] * COUNT[ogX+absDiff][ogY] * COUNT[ogX+absDiff][ogY + diff]);
        }
        return res;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */