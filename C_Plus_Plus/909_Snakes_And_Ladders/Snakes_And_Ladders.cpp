#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int minMoves = -1;
        vector<bool> visited(board.size() * board[0].size(), false);
        //minMoves = dfs(1, board, visited, 0, -1);
        minMoves = bfs(1, board, visited);
        return minMoves;
    }

    int bfs(int curr, vector<vector<int>> &board, vector<bool> &visited) {
        int steps = 0;
        int end = board.size() * board[0].size();
        queue<int> visitQueue({curr});

        while (!visitQueue.empty())
        {
            size_t loopNum = visitQueue.size();

            for(size_t i = 0; i < loopNum; ++i)
            {
                int curr = visitQueue.front();
                visitQueue.pop();

                if (visited[curr -1]){
                    continue;
                }
                
                int row, col;
                calcRowAndColumn(curr, board, row, col);

                if(board[row][col] != -1){
                    int jumpTo = board[row][col];
                    curr = jumpTo;
                }

                if (curr == end){
                    return steps;
                }
                
                visited[curr - 1] = true;

                for(int nextPos = curr + 1; nextPos <= min(curr + 6, end); ++nextPos){
                    visitQueue.push(nextPos);
                }
            }

            ++steps;
        }

        return -1;
    }

    int dfs(int curr, vector<vector<int>> &board, vector<bool> &visited, int steps, int minSteps) {
        if(visited[curr - 1])
            return -1;
            
        visited[curr - 1] = true;
        int row, col;
        int totalSteps = -1;
        int jumpedFrom = -1;
        calcRowAndColumn(curr, board, row, col);
            
        if(curr == board.size() * board[0].size() || board[row][col] == board.size() * board[0].size()){
                visited[curr - 1] = false;
                return steps;
        }

        if(board[row][col] != -1){
            int jumpTo = board[row][col];
            if(visited[jumpTo - 1]){
                visited[curr - 1] = false;
                return -1;
            }
            //totalSteps = dfs(board[row][col], board, visited, steps);
            //visited[curr - 1] = false;
            jumpedFrom = curr;
            curr = jumpTo;
            visited[curr - 1] = true;
            calcRowAndColumn(curr, board, row, col);
            return totalSteps;
        }
        
        if (steps + 1 >= totalSteps && totalSteps != -1)
            return -1;

        for(int i = curr + 1; i <= min(curr + 6, static_cast<int>(board.size() * board[0].size())); ++i) {
            int tempSteps = dfs(i, board, visited, steps + 1, totalSteps);
            totalSteps = (totalSteps == -1) ? tempSteps : min(totalSteps, tempSteps);
        }

        visited[curr - 1] = false;
        if(jumpedFrom != -1)
            visited[jumpedFrom - 1] = false;
        return totalSteps;
    }

    void calcRowAndColumn(int curr, vector<vector<int>> &board, int &row, int &col){
        int rows = board.size();
        int cols = board[0].size();
        
        row = rows - ((curr - 1) / cols) - 1;
        col = ((rows - row - 1) % 2 == 0) ? (curr - 1) % cols : cols - ((curr - 1) % cols) - 1;
    }
};

int main(int argc, char ** args)
{
    Solution sol;
    vector<vector<int>> board = {{-1, -1}, {-1, 3}};
    sol.snakesAndLadders(board);
    return 0;
}