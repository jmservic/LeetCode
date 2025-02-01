#include <vector>
#include <algorithm>

using namespace::std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();

        sort(nums.begin(), nums.end());
        int consecutive = 1;
        int lastNum = nums[0];
        int maxConsecutive = 0;

        for (size_t i = 1; i < nums.size(); ++i){
            if (nums[i] == lastNum + 1)
                ++consecutive;
            else if (nums[i] != lastNum)
            {
                maxConsecutive = (consecutive > maxConsecutive) ? consecutive : maxConsecutive;
                consecutive = 1;
            }

            lastNum = nums[i];
        }

        return (maxConsecutive > consecutive) ? maxConsecutive : consecutive;
    }
};

int main(int argc, char ** args) {

    return 0;
}