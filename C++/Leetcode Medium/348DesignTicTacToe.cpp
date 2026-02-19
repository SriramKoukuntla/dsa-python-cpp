#include <vector>
using namespace std;
class TicTacToe {
public:
    vector<vector<int>> board;
    TicTacToe(int n) {
        board = vector<vector<int>>(n, vector<int>(n, -1));
    }
    
    int move(int row, int col, int player) {
        //set board position to player
        board[row][col] = player;

        bool horizontalConnection = true;
        //checking horizontal connection
        for (int i = 0; i < board[0].size(); ++i) {
            if (board[row][i] != player) {
                horizontalConnection = false;
                break;
            }
        }

        bool verticalConnection = true;
        //checking vertical connection
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][col] != player) {
                verticalConnection = false;
                break;
            }
        }

        bool diagonalConnection = false;
        //checking for diagonal connection
        if (row == col) {
            diagonalConnection = true;
            for (int i = 0; i < board.size(); ++i) {
                for (int j = i; j < i+1; ++j) {
                    if (board[i][j] != player) {
                        diagonalConnection = false;
                    }
                    if (!diagonalConnection) break;
                }
                if (!diagonalConnection) break;
            }
        }
        if (diagonalConnection) return player;

        if (row + col == board.size()-1) {
            diagonalConnection = true;
            for (int i = 0; i < board.size(); ++i) {
                if (board[board.size()-1-i][i] != player) {
                    diagonalConnection = false;
                }
            }
        }
        if (diagonalConnection) return player;

        return (horizontalConnection || verticalConnection || diagonalConnection) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */