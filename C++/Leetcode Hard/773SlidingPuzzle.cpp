#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void helper(vector<vector<int>>& state, unordered_map<string, int>& reachableStates, int moves) {
        string stringState;
        for (vector<int>& half : state) for (int num : half) stringState += to_string(num);

        if (reachableStates.find(stringState) == reachableStates.end()) reachableStates[stringState] = moves;
        else if (reachableStates[stringState] > moves) reachableStates[stringState] = moves;
        else if (reachableStates[stringState] <= moves) return;

        int i = -1; int j = -1;
        for (int r = 0; r < state.size(); ++r) for (int k = 0; k < state[0].size(); ++k) if (state[r][k] == 0) {i = r; j = k; break;}

        if (j-1 >= 0) { //Left Swap
            swap(state[i][j], state[i][j-1]);
            helper(state, reachableStates, moves+1);
            swap(state[i][j], state[i][j-1]);
        }
        if (j+1 < state[0].size()) { //Right Swap
            swap(state[i][j], state[i][j+1]);
            helper(state, reachableStates, moves+1);
            swap(state[i][j], state[i][j+1]);        
        }
        if (i - 1 >= 0 ) { //Up Swap
            swap(state[i][j], state[i-1][j]);
            helper(state, reachableStates, moves+1);
            swap(state[i][j], state[i-1][j]);
        }
        if (i + 1 < state.size()) { //Down Swap
            swap(state[i][j], state[i+1][j]);
            helper(state, reachableStates, moves+1);
            swap(state[i][j], state[i+1][j]);
        }
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, int> reachableStates;
        vector<vector<int>> initialState = {{1, 2, 3}, {4, 5, 0}};
        helper(initialState, reachableStates, 0);

        string stringState;
        for (vector<int>& half : board) for (int num : half) stringState += to_string(num);

        return (reachableStates.find(stringState) == reachableStates.end()) ? -1 : reachableStates[stringState];
    }
};