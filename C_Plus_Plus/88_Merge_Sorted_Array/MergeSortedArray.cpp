#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int currPos = m + n - 1;

        while(currPos > -1) 
        {
            if (index1 > -1 && index2 > -1)
            {
                if (nums1[index1] > nums2[index2]) 
                    nums1[currPos--] = nums1[index1--];
                else
                    nums1[currPos--] = nums2[index2--];
            } 
            else if (index1 > -1)
                currPos = -1;
            else if (index2 > -1)
                nums1[currPos--] = nums2[index2--];
        }
    }
};

main(int argc, char ** args)
{
    vector<int> nums1{1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2{2,5,6};
    int n = 3;
    Solution sol;

    sol.merge(nums1, m, nums2, n);
    for(int num : nums1)
        cout << num << " ";
    return 0;
}