#include <string>
#include <algorithm>
#include <iostream>
#include <ios>
#include <set>
using namespace std;
class Solution {
public:
   bool isHappy(int n) {
        set<int> seenNumbers;
        seenNumbers.insert(n);
        int prevNum = n;
        int temp;
        while(n != 1)
        {
            n = 0;
            while(prevNum > 0)
            {
                temp = prevNum % 10;
                n += (temp * temp);
                prevNum /= 10;
            }
            if(seenNumbers.contains(n))
                return false;
            else
            {
                seenNumbers.insert(n);
                prevNum = n;
            }
        }
        return true;
    }
};


int main(int argc, char ** args)
{
    Solution sol;
    auto results = sol.isHappy(19);

    return 0;
}