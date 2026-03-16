#include <vector>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<float> tower = {1.0f * poured};

        int currIdx = 0;
        int currRow = 0; //currRow is zero indexed
        bool glassOverFlowed = true;
        while (glassOverFlowed) {
            glassOverFlowed = false;
            for (int i = 0; i < currRow+2; ++i) tower.push_back(0); //add 0s for next row 1 indexed
            for (int currGlass = 0; currGlass < currRow+1; ++currGlass) { //process every element in current row
                if (tower[currIdx] > 1) { //overflow case
                    glassOverFlowed = true;
                    float overFlowEachSide = (tower[currIdx] - 1)/2.0;
                    tower[currIdx] = 1;
                    tower[currIdx + (currRow+1)] += overFlowEachSide; //left glass next row
                    tower[currIdx + (currRow+1) + 1] += overFlowEachSide; //right glass next row
                }
                if (query_row == currRow && currGlass == query_glass) return tower[currIdx];
                ++currIdx;
            }
            ++currRow;
        }
        return 0;
    }
};
//sum(of cups in all rows that we need to consider) 
//base case = we fill cup or we get less than cup
//recursion case = we get spillage, so we call left and right
//fill it in some 2d array
//for the actual function we query this 2d array O(1)
//i = cup index 
//query row = n
//cup poured = 1 + ... + n; o(1)
//
//(1 = 0), 
//(2, 1), (3, 2), 
//(4, 3), (5, 4), (6, 5)

//1d array
//{2} //row = 1
//{1, 0.5, 0.5} //row = 2
//{1, 1, 1, 0.5, 1, 0.5} //row = 3