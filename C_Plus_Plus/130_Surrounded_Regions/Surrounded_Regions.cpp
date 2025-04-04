#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        unordered_set<char *> visited;

        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(!visited.contains(&board[row][col]))
                {
                    if(isSurrounded(board, row, col, visited))
                        CaptureRegion(board, row, col, visited);
                }
            }
        }
    }

    void solveQuick(vector<vector<char>>& board)
    {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        for(int row = 0; row < rows; ++row)
        {
            if(board[row][0] == 'O') visit(board, row, 0, visited);
            if(board[row][cols - 1] == 'O') visit(board, row, cols - 1, visited);
        }

        for(int col = 1; col < cols - 1; ++col)
        {
            if(board[0][col] == 'O') visit(board, 0, col, visited);
            if(board[rows - 1][col] == 'O') visit(board, rows - 1, col, visited);
        }

        for(int row = 1; row < rows - 1; ++rows)
        {
            for(int col = 1; col < cols - 1; ++col)
            {
                if(!visited[row][col] && board[row][col] == 'O')
                    board[row][col] = 'X';
            }
        }        
    }

    void visit(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited) 
    {
        visited[row][col] = true;
        if(board[row][col] == 'O')
        {
            int rows = board.size();
            int cols = board[0].size();

            for(int rowOffset = -1; rowOffset < 2; rowOffset += 2)
            {
                int checkRow = row + rowOffset;
                int checkCol = col;
                if(checkRow >= 0 && checkRow < rows)
                {
                    if(!visited[checkRow][checkCol]&& board[checkRow][checkCol] == 'O')
                        visit(board, checkRow, checkCol, visited);            
                }
            }

            for(int colOffset = -1; colOffset < 2; colOffset += 2)
            {
                int checkRow = row;
                int checkCol = col + colOffset;
                if(checkCol >= 0 && checkCol < cols)
                {
                    if(!visited[checkRow][checkCol] && board[checkRow][checkCol] == 'O') 
                        visit(board, checkRow, checkCol, visited);              
                }
            }
        }    

    }


    void CaptureRegion(vector<vector<char>>& board, int row, int col,unordered_set<char *>& visited)
    {
        
        if(board[row][col] == 'O')
        {
            int rows = board.size();
            int cols = board[0].size();
            board[row][col] = 'X';
            for(int rowOffset = -1; rowOffset < 2; rowOffset += 2)
            {
                int checkRow = row + rowOffset;
                int checkCol = col;
                if(checkRow >= 0 && checkRow < rows)
                {
                    if(board[checkRow][checkCol] == 'O')
                        CaptureRegion(board, checkRow, checkCol, visited);            
                }
            }

            for(int colOffset = -1; colOffset < 2; colOffset += 2)
            {
                int checkRow = row;
                int checkCol = col + colOffset;
                if(checkCol >= 0 && checkCol < cols)
                {
                    if(board[checkRow][checkCol] == 'O') 
                        CaptureRegion(board, checkRow, checkCol, visited);              
                }
            }
        } 
    }

    bool isSurrounded(vector<vector<char>>& board, int row, int col,unordered_set<char *>& visited) 
    {
        visited.insert(&board[row][col]);
        if(board[row][col] == 'X') return true;
        int rows = board.size();
        int cols = board[0].size();
        bool surrounded = true;

        for(int rowOffset = -1; rowOffset < 2; rowOffset += 2)
        {
            int checkRow = row + rowOffset;
            int checkCol = col;
            if(checkRow >= 0 && checkRow < rows)
            {
                if(!visited.contains(&board[checkRow][checkCol])) 
                {
                    if(surrounded)
                    {
                        surrounded = isSurrounded(board, checkRow, checkCol, visited);
                    } else
                        visitCell(board, checkRow, checkCol, visited);

                }                
            } else
                surrounded = false;
        }

        for(int colOffset = -1; colOffset < 2; colOffset += 2)
        {
            int checkRow = row;
            int checkCol = col + colOffset;
            if(checkCol >= 0 && checkCol < cols)
            {
                if(!visited.contains(&board[checkRow][checkCol])) 
                {
                    if(surrounded)
                    {
                        surrounded = isSurrounded(board, checkRow, checkCol, visited);
                    } else 
                        visitCell(board, checkRow, checkCol, visited);
                }                
            } else
                surrounded = false;    
        }

        return surrounded;
    }

    void visitCell(vector<vector<char>>& board, int row, int col,unordered_set<char *>& visited)
    {
        visited.insert(&board[row][col]);
        if(board[row][col] == 'O')
        {
            int rows = board.size();
            int cols = board[0].size();

            for(int rowOffset = -1; rowOffset < 2; rowOffset += 2)
            {
                int checkRow = row + rowOffset;
                int checkCol = col;
                if(checkRow >= 0 && checkRow < rows)
                {
                    if(!visited.contains(&board[checkRow][checkCol]) && board[checkRow][checkCol] == 'O')
                        visitCell(board, checkRow, checkCol, visited);            
                }
            }

            for(int colOffset = -1; colOffset < 2; colOffset += 2)
            {
                int checkRow = row;
                int checkCol = col + colOffset;
                if(checkCol >= 0 && checkCol < cols)
                {
                    if(!visited.contains(&board[checkRow][checkCol]) && board[checkRow][checkCol] == 'O') 
                        visitCell(board, checkRow, checkCol, visited);              
                }
            }
        }    
    }
};

int main(int argc, char ** args)
{
    vector<int> temp = {1, 2, 3, 4};
    vector<char> temp2 = {'X','O','X'};
    vector<vector<char>> board = {{'X','O','X'}, {'X','O','X'}, {'X','O','X'}};
    Solution sol;
    sol.solveQuick(board);
    return 0;
}