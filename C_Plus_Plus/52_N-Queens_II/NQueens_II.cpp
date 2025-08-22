#include <vector>
#include <math.h>
#include <functional>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int total = 0;
        vector<pair<int, int>> queens;
        Solve(queens, n, total, 1);
        return total;
    }

    void Solve(vector<pair<int, int>> queens, const int &n, int &total, int row)
    {
        for (int i = 1; i <= n; ++i )
        {
            if(!ValidPosition(row, i, queens)) continue;
            queens.push_back(make_pair(row, i));
            if (row == n) 
            {
                ++total;
            } else {
                Solve(queens, n, total, row + 1);
            }
            queens.pop_back();
        }

    }

    bool ValidPosition(int row, int column, vector<pair<int, int>> queens) {
        for (pair<int, int> queen : queens) {
            if (queen.first == row || queen.second == column) {
                return false;
            }
            int row_dist = abs(queen.first - row);
            int col_dist = abs(queen.second - column);
            if (row_dist == col_dist) {
                return false;
            }
        }

        return true;
    }

    int totalNQueensSecondAttemp(int n) {
        int total = 0;
        bool columns[n] {false};
        bool diag1[2 * n - 1] {false};
        bool diag2[2 * n - 1] {false};

        function<void(int)> backtrack = [&] (int row) {
            for (int i = 0; i < n; ++i) {
                if (columns[i] || diag1[row + i] || diag2[row - i + n]) continue;
                columns[i] = diag1[row + 1] = diag2[row - i + n] = true;
                if (row == n -1)
                    ++total;
                else
                    backtrack(row + 1);
                columns[i] = diag1[row + 1] = diag2[row - i + n] = false;
            }
        };

        backtrack(0);
        return total;
    }
};