#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        bool zeroFirstRow = false;
        bool zeroFirstColumn = false;

        for (size_t row = 0; row < matrix.size(); ++row)
        {
            for (size_t col = 0; col < matrix[0].size(); ++col)
            {
                if(matrix[row][col] == 0)
                {
                    if(row != 0)
                        matrix[row][0] = 0;
                    else
                        zeroFirstRow = true;
                    
                    if(col != 0)
                        matrix[0][col] = 0;
                    else
                        zeroFirstColumn = true;
                }
            }
        }
        //cout << "I Ran" << endl;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        while(row >= 0 || col >= 0)
        {
            if((row >= col && matrix[row][0] == 0 && row != 0) || 
                (row == 0 && zeroFirstRow))
            {
                //cout << "zeroing out row " << row + 1 << endl;
                for(size_t j = (row == 0) ? 0 : 1; j < matrix[0].size(); ++j)
                    matrix[row][j] = 0;
            }

            if((col >= row && matrix[0][col] == 0 && col != 0) ||
                (col == 0 && zeroFirstColumn))
            {
                //cout << "zeroing out col " << col + 1 << endl;
                for(size_t i = (col == 0) ? 0 : 1; i < matrix.size(); ++i)
                    matrix[i][col] = 0;  
            }

            //cout << "row = " << row << " | col = " << col << endl;
            if(row == col)
            {
                row--;
                col--;
            } 
            else if(row > col)
                row--;
            else if(col > row)
                col--;
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

main(int argc, char** argv)
{
    Solution sol;
    vector<vector<int>> case1{{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> case2{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> case3{{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};

    cout << "Initial Case 1:" << endl;
    printMatrix(case1);
    sol.setZeroes(case1);
    cout << "======== \n" << "Post Case 1:" << endl;
    printMatrix(case1);
    cout << "\n\n";

    cout << "Initial Case 2:" << endl;
    printMatrix(case2);
    sol.setZeroes(case2);
    cout << "======== \n" << "Post Case 2:" << endl;
    printMatrix(case2);
    cout << "\n\n";

    cout << "Initial Case 3:" << endl;
    printMatrix(case3);
    sol.setZeroes(case3);
    cout << "======== \n" << "Post Case 3:" << endl;
    printMatrix(case3);
    cout << "\n\n";
    return 0;
}