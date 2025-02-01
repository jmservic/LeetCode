#include <algorithm>
#include <iostream>
#include <ios>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> indexes;
        map.insert({nums[0], 0});

        for(int i = 1; i < nums.size(); ++i)
        {
            int otherVal = target - nums[i];
            if(map.contains(otherVal))
            {
                indexes.emplace_back(map[otherVal]);
                indexes.emplace_back(i);
                return indexes;
            } else
            {
                map.insert({nums[i], i});
            }
        }

        return indexes;
    }
};


int main(int argc, char ** args)
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution sol;

    sol.twoSum(nums, target);
    return 0;
}