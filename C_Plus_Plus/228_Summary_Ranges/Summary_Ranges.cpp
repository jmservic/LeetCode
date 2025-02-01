#include <vector>
#include <string>
#include <sstream>

using namespace::std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        if(nums.size() < 1)
            return ranges;

        int rangeStart = nums[0];
        stringstream strStream;


        for(size_t i = 0; i < nums.size() - 1; ++i){
            if(nums[i + 1] != nums[i] && nums[i + 1] != nums[i] + 1) 
            {
                strStream << to_string(rangeStart).c_str();

                if(nums[i] != rangeStart)
                    strStream << "->" << to_string(nums[i]);
                
                ranges.push_back(strStream.str());
                strStream.str("");
                rangeStart = nums[i + 1];
            }
        }

        strStream << to_string(rangeStart).c_str();

        if(nums[nums.size() - 1] != rangeStart)
            strStream << "->" << to_string(nums[nums.size() - 1]);
        
        ranges.push_back(strStream.str());

        return ranges;        
    }
};

int main(int argc, char ** args){

    return 0;
}