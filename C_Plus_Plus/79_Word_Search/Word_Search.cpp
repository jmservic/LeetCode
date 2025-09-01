#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool * visited[board.size()];
        for (int i = 0; i < board.size(); ++i) {
            visited[i] = new bool[board[0].size()] {false};
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    if (search(visited, word, board, i, j, 1)) {
                        for (int n = 0; n < board.size(); ++n) {
                            delete [] visited[n];
                        }
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            delete [] visited[i];
        }
        return false;
    }

    bool search(bool **visited, const string &word, const vector<vector<char>> &board, int row, int col, int index) {
        if (index == word.length()) return true;
        
        char l = word[index];

        // Left
        if (col > 0 && board[row][col - 1] == l && !visited[row][col - 1]) {
            visited[row][col - 1] = true;
            if (search(visited, word, board, row, col - 1, index + 1)) return true;
            visited[row][col - 1] = false;
        }

        // Top
        if (row > 0 && board[row - 1][col] == l && !visited[row - 1][col]) {
            visited[row - 1][col] = true;
            if (search(visited, word, board, row - 1, col, index + 1)) return true;
            visited[row - 1][col] = false;
        }

        // Right
        if (col < board[0].size() - 1 && board[row][col + 1] == l && !visited[row][col + 1]) {
            visited[row][col + 1] = true;
            if (search(visited, word, board, row, col + 1, index + 1)) return true;
            visited[row][col + 1] = false;
        }

        // Bottom
        if (row < board.size() - 1 && board[row + 1][col] == l && !visited[row + 1][col]) {
            visited[row + 1][col] = true;
            if (search(visited, word, board, row + 1, col, index + 1)) return true;
            visited[row + 1][col] = false;
        }
        
        return false;
    }
};