#include <string>
#include <algorithm>
#include <iostream>
#include <ios>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int map[26] = {0};
        for_each(s.cbegin(), s.cend(), [&map](char c){++map[c - 'a'];});

        for(char c : t)
        {
            cout << map[c - 'a'] << " " << endl;
            if(map[c - 'a'] == 0)
                return false;
            --map[c - 'a'];
        }

        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        
        for(string &str : strs)
        {
            bool foundGroup = false;
            for(vector<string> & group : groups)
            {
                if(isAnagram(group[0], str))
                {
                    group.emplace_back(str);
                    foundGroup = true;
                    break;
                }
            }
            
            if(!foundGroup)
                groups.emplace_back(vector{str});
        }

        return groups;
    }
};


int main(int argc, char ** args)
{
    Solution sol;
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    auto results = sol.groupAnagrams(strs);
    for(auto group : results)
    {
        for(auto str : group)
            cout << str << " ";
    }
    return 0;
}