#include <vector>
#include <algorithm>

using namespace::std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> merged;
        //could've done without the additional vector, and just use an int value that held the upperbound and incremented the arrow based on whether or not the next interval's lowerbound was greater than the int value.ggi
        for (auto interval : points)
        {
            if(merged.empty() || interval[0] > merged.back()[1])
                merged.push_back(interval);
            else
            {
                merged.back()[0] = max(merged.back()[0], interval[0]);
                merged.back()[1] = min(merged.back()[1], interval[1]);
            }
        }

        return merged.size();
    }
};

int main( int argc, char ** args){

    return 0;
}