#include <vector>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandNum = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(grid[row][col] == '1')
                {
                    ++islandNum;
                    zeroConnectedLand(grid, row, col);
                }

            }
        }

        return islandNum;
    }

    void zeroConnectedLand(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';
        if(row > 0 && grid[row - 1][col] == '1')
            zeroConnectedLand(grid, row - 1, col);
        if(col < grid[row].size() - 1 && grid[row][col + 1] == '1')
            zeroConnectedLand(grid, row, col + 1);
        if(row < grid.size() - 1 && grid[row + 1][col] == '1')
            zeroConnectedLand(grid, row + 1, col);
        if(col > 0 && grid[row ][col - 1] == '1')
            zeroConnectedLand(grid, row, col - 1);
    }
};