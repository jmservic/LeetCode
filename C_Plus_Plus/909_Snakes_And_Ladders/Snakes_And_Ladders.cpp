#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int minMoves = -1;
        vector<bool> visited(board.size() * board[0].size(), false);
        minMoves = dfs(1, board, visited, 0);
        return minMoves;
    }

    int dfs(int curr, vector<vector<int>> &board, vector<bool> &visited, int steps) {
        if(visited[curr - 1])
            return -1;
        
        visited[curr - 1] = true;
        int row, col;
        int totalSteps = -1;
        calcRowAndColumn(curr, board, row, col);

        if(board[row][col] != -1){
            totalSteps = dfs(board[row][col], board, visited, steps);
            visited[curr + 1] = false;
            return totalSteps;
        }

        if(curr == board.size() * board[0].size()){
            visited[curr + 1] = false;
            return steps;
        }

        for(int i = curr + 1; i <= min(curr + 6, static_cast<int>(board.size() * board[0].size())); ++i) {
            int tempSteps = dfs(i, board, visited, steps + 1);
            totalSteps = (totalSteps == -1) ? tempSteps : min(totalSteps, tempSteps);
        }

        visited[curr + 1] = false;
        return totalSteps;
    }

    void calcRowAndColumn(int curr, vector<vector<int>> &board, int &row, int &col){
        
    }
};