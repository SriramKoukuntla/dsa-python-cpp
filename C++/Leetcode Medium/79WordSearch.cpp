//Back tracking solution. Instead of using hashmaps, use 2d bool vector to store visited.
#include <unordered_set>
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        bool res = false;
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                helper(board, word, visited, 0, i, j, res);
            }
        }
        return res;
    }
    void helper(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int ptr, int x, int y, bool& res){
        if (res == true) return;
        if (ptr == word.size()) {
            res = true;
            return;
        }
        //Out of bounds, Not desired letter, Already Visited
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[ptr] || visited[x][y]){
            return;
        }
        visited[x][y] = true;
        helper(board, word, visited, ptr + 1, x - 1, y, res); 
        helper(board, word, visited, ptr + 1, x + 1, y, res); 
        helper(board, word, visited, ptr + 1, x, y - 1, res); 
        helper(board, word, visited, ptr + 1, x, y + 1, res); 
        visited[x][y] = false;
    }
};