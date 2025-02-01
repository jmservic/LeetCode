#include <vector>
#include <algorithm>
#include <list>

using namespace::std;
template class vector<vector<int>>;
template class list<vector<int>>;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    /*    if (intervals.size() == 1)
            return intervals;

        list<vector<int>> mergedIntervals;
        for (auto interval : intervals){
            auto it = mergedIntervals.begin();

            while (it != mergedIntervals.end())
            {
                if (overlap(interval, *it)) 
                {
                    interval[0] = min(interval[0], it->at(0));
                    interval[1] = max(interval[1], it->at(1));
                    it = mergedIntervals.erase(it);
                } else
                    ++it;
            }

            mergedIntervals.push_back(interval);

        }

        vector<vector<int>> vecMergedIntervals(mergedIntervals.begin(), mergedIntervals.end());
        return vecMergedIntervals; */

        /******* Slow attempt.... Fast attempt without the merged Interval loop... **********/
        sort(intervals.begin(), intervals.end(), [] (const vector<int> &left, vector<int> &right) {return left[0] < right[0];});
        vector<vector<int>> mergedIntervals;

        for (auto interval : intervals){
            if(mergedIntervals.empty() || mergedIntervals.back()[1] < interval[0])
                mergedIntervals.push_back(interval);
            else
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], interval[1]);
            /*bool merged = false;
            for (auto &mergedInterval : mergedIntervals)
            {
                if (interval[0] >= mergedInterval[0] && interval[0] <= mergedInterval[1]){
                    mergedInterval[1] = (interval[1] > mergedInterval[1]) ? interval[1] : mergedInterval[1];
                    merged = true;
                    break;
                } else if (interval[1] >= mergedInterval[0] && interval[1] <= mergedInterval[1]) {
                    mergedInterval[0] = (interval[0] < mergedInterval[0]) ? interval[0] : mergedInterval[0];
                    merged = true;
                    break;
                } else if (mergedInterval[0] > interval[0] && mergedInterval[1] < interval[1]){
                    mergedInterval[0] = interval[0];
                    mergedInterval[1] = interval[1];
                    merged = true;
                    break;
                }
            }
            if (!merged)
                mergedIntervals.push_back(interval); */
        }
        return mergedIntervals;

     /*   auto it = mergedIntervals.begin();
        while (it != mergedIntervals.end() && ++it != mergedIntervals.end()){
            auto next = it;
            --it;
            if ((*it)[1] >= (*next)[0] && (*it)[0] <= (*next)[1]) {
                (*it)[0] = min((*it)[0], (*next)[0]);
                (*it)[1] = max((*it)[1], (*next)[1]);
                mergedIntervals.erase(next);
            } else
                ++it;
        } */

    }

    bool overlap(vector<int> interval1, vector<int> interval2)
    {
        return ((interval1[0] >= interval2[0] && interval1[0] <= interval2[1]) || //lower bound is within interval 2
                (interval1[1] >= interval2[0] && interval1[1] <= interval2[1]) || //upper bound is within interval 2
                (interval1[0] < interval2[0] && interval1[1] > interval2[1]) //interval 2 is a subset of interval 1
        );
    }
};

int main(int argc, char ** args) {
    vector<vector<int>> intervals {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution sol;
    sol.merge(intervals);
    return 0;
}