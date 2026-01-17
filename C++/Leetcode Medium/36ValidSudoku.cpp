#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            unordered_set<char> row;
            unordered_set<char> column;
            unordered_set<char> block;
            for (int j = 0; j < board[0].size(); ++j){
                if (collision(row, i, j, board)) return false;
                if (collision(column, j, i, board)) return false;
                if (collision(block, ((i/3)*3) + (j/3), ((i%3)*3) + (j%3), board)) return false;
            }
        }
        return true;
    }
    bool collision(unordered_set<char>& set, int i, int j, vector<vector<char>>& board){
        char entry = board[i][j];
        if (entry == '.' || entry == ',') return false;
        if (set.find(entry) != set.end()) return true;
        set.insert(entry);
        return false;
    }
};