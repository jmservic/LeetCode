#include <vector>
#include <unordered_map>


using namespace::std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int currVal;
        for (int i = 0; i < nums.size(); ++i){
            currVal = nums[i];
            if (map.contains(currVal)) {
                if (i - map[currVal] <= k)
                    return true;
                else
                    map[currVal] = i;
            } else {
                map.insert({currVal, i});
            }
        }

        return false;
    }
};

int main(int argc, char ** args) 
{
    vector case1 = {1, 2, 3, 1};
    int k1 = 3;
    Solution sol;
    sol.containsNearbyDuplicate(case1, k1);

    return 0;
}