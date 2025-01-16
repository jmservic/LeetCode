#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_set<string> set;
        size_t searchIndex = 0;
        size_t spacePos = 0;
        string currWord;

        for(size_t i = 0; i < pattern.length(); ++i)
        {
            auto firstIt = map.find(pattern[i]);
            if(searchIndex >= s.length()) return false;
            spacePos = s.find(" ", searchIndex);
            if(spacePos == string::npos) spacePos = s.length();
            //cout << "The searchIndex is " << searchIndex << " while the spacePos is " << spacePos << endl;
            currWord = s.substr(searchIndex, spacePos - searchIndex);
            searchIndex = spacePos + 1;

            //cout << currWord << endl;

            auto secondIt = set.find(currWord);
            if(firstIt == map.end() && secondIt == set.end())
            {
                map.insert({pattern[i], currWord});
                set.insert(currWord);

            } else if((firstIt == map.end() || secondIt == set.end()) ||
                    (firstIt->second != *secondIt))
                return false;
        }

        return spacePos == s.length();
    }
};


int main(int argc, char ** args)
{
    Solution sol;
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << sol.wordPattern(pattern, s) << endl;

    return 0;
}