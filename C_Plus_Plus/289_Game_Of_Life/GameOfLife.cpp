#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                char neighborCount = 0;
                int cellValue = board[row][col];
                for(int i = (row - 1 < 0) ? 0 : row - 1; i <= row + 1 && i < rows; ++i)
                {
                    for(int j = (col - 1 < 0) ? 0 : col - 1; j <= col + 1 && j < cols; ++j)
                    {
                        if(i != row || j != col)
                        {
                            if(board[i][j] > 0)
                                ++neighborCount;
                        }
                    }
                }
                
                if((neighborCount < 2 || neighborCount > 3) && cellValue == 1)
                    board[row][col] = 2;
                else if(neighborCount == 3 && cellValue == 0)
                    board[row][col] = -1;                
            }
        }

        //2 represents under and overpopulation death while -1 represents dead cell coming alive
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(board[row][col] == 2)
                    board[row][col] = 0;
                else if(board[row][col] == -1)
                    board[row][col] = 1;
            }
        }        
    }
};

void printMatrix(const vector<vector<int>>& matrix)
{
    for(vector<int> row : matrix)
    {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
}

main(int argc, char** args)
{
    Solution sol;
    vector<vector<int>> case1{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};

    cout << "Initial Case 1:" << endl;
    printMatrix(case1);
    sol.gameOfLife(case1);
    cout << "======== \n" << "Post Case 1:" << endl;
    printMatrix(case1);
    cout << "\n\n";
    return 0;
}