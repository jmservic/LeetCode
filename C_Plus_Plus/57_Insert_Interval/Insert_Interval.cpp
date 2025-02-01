#include <vector>
#include <algorithm>
using namespace::std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        auto lowerBound = intervals.begin();
        //Find position of lower bound
        DetermineInsertPos(lowerBound, newInterval[0], intervals.end());

        //Find position of upper bound
        auto upperBound = lowerBound;
        DetermineInsertPos(upperBound, newInterval[1], intervals.end());
        if(upperBound != intervals.end() && upperBound != intervals.begin() && upperBound->at(0) > newInterval[1]) --upperBound;

        //cases
        //1. Both iterators equal the same value
        if(lowerBound != intervals.end() && lowerBound == upperBound)
        {             //Update that value
            if(overlap(newInterval, *lowerBound)) 
            {
                lowerBound->at(0) = min(newInterval[0], lowerBound->at(0));
                lowerBound->at(1) = max(newInterval[1], lowerBound->at(1));
            } else
                intervals.insert(lowerBound, newInterval);
        } else if (lowerBound == intervals.end() && upperBound == intervals.end()) //2. Both iterators are equal to the end
        {
            //Need to insert at the end.
            intervals.push_back(newInterval);
        } else if (upperBound == intervals.end()) //3. upper bound equal to end
        {
            newInterval[0] = min(newInterval[0], lowerBound->at(0));
            intervals.erase(lowerBound, intervals.end());
            intervals.push_back(newInterval);
        } else //4. lower and upper bound are different.
        {
            //Adjust the new interval with the lowest and highest value
            newInterval[0] = min(newInterval[0], lowerBound->at(0));
            newInterval[1] = max(newInterval[1], upperBound->at(1));
            //Remove the range
            ++upperBound;
            intervals.erase(lowerBound, upperBound);
            //insert the newInterval into that position
            lowerBound = intervals.begin();
            DetermineInsertPos(lowerBound, newInterval[0], intervals.end());
            intervals.insert(lowerBound, newInterval);
        }

        return intervals;
    }

    void DetermineInsertPos(vector<vector<int>>::iterator &it, int value, vector<vector<int>>::iterator end)
    {
        while(it != end && value > it->at(0) && value > it->at(1))
            ++it;
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
    vector<vector<int>> intervals = {{1,5}};//{{1, 3}, {6,9}};//{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {0,3};//{2, 5};// {4, 8};
    Solution sol;
    sol.insert(intervals, newInterval);
    return 0;
}