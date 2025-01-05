#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board)
        {
            int tempVal;
            //Check rows and columns
            for(size_t i = 0; i < board.size(); ++i)
            {
                vector<bool> foundValues(9, false);
                //row
                for(size_t index = 0; index < board[i].size(); ++index)
                {
                    if(board[i][index] != '.')
                    {
                        tempVal = board[i][index] - '0';
                        if(foundValues[tempVal - 1])
                            return false;
                        else
                            foundValues[tempVal - 1] = true;
                    }
                }

                //column
                foundValues = vector(9, false);
                for(size_t index = 0; index < board.size(); ++index)
                {
                    if(board[index][i] != '.')
                    {
                        tempVal = board[index][i] - '0';
                        if(foundValues[tempVal - 1])
                            return false;
                        else
                            foundValues[tempVal - 1] = true;
                    }
                }
            }

            //check sub-boxes
            for(size_t i = 0; i < board.size(); i += 3)
            {
                for(size_t j = 0; j < board[i].size(); j += 3)
                {
                    vector<bool> foundValues(9, false);
                    for(size_t row = i; row < i + 3; ++row)
                    {
                        for(size_t col = j; col < j + 3; ++col)
                        {
                            if(board[row][col] != '.')
                            {
                                tempVal = board[row][col] - '0';
                                if(foundValues[tempVal - 1])
                                    return false;
                                else
                                    foundValues[tempVal - 1] = true;
                            }
                        }
                    }
                }
            }

            return true;
        }
};


main(int argc, char** argv)
{
    Solution sol;
    vector<vector<char>> case1;
    case1.emplace_back(vector({'5','3','.','.','7','.','.','.','.'}));
    case1.emplace_back(vector({'6','.','.','1','9','5','.','.','.'}));
    case1.emplace_back(vector({'.','9','8','.','.','.','.','6','.'}));
    case1.emplace_back(vector({'8','.','.','.','6','.','.','.','3'}));
    case1.emplace_back(vector({'4','.','.','8','.','3','.','.','1'}));
    case1.emplace_back(vector({'7','.','.','.','2','.','.','.','6'}));
    case1.emplace_back(vector({'.','6','.','.','.','.','2','8','.'}));
    case1.emplace_back(vector({'.','.','.','4','1','9','.','.','5'}));
    case1.emplace_back(vector({'.','.','.','.','8','.','.','7','9'}));

    cout << boolalpha;
    cout << "Case 1 Output: " << sol.isValidSudoku(case1) << endl; // expecting true.
    return 0;
}