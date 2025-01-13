#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
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

int main(int argc, char ** args)
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums1Size = 6;
    int m = 3;
    int nums2[] = {2, 5, 6};
    int nums2Size = 3;
    int n = 3;
    merge(nums1, nums1Size, m, nums2, nums2Size, n); 
    int index;
    
    for(index = 0; index < nums1Size; ++index)
    {
        printf("%d ", nums1[index]);
    }
    return 0;
}