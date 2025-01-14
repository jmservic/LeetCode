#include <string>
#include <iostream>
#include <ios>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> set;
        for(size_t i = 0; i < s.length(); ++i)
        {
            auto firstIt = map.find(s[i]);
            auto secondIt = set.find(t[i]);
            if(firstIt == map.end() && secondIt == set.end())
            {
                map.insert({s[i], t[i]});
                set.insert(t[i]);

            } else if((firstIt == map.end() || secondIt == set.end()) ||
                    (firstIt->second != *secondIt))
                return false;
        }

        return true;
    }
};
int main(int argc, char** args)
{
    string s = "paper";
    string t = "title";
    Solution sol;
    cout << boolalpha;
    cout << sol.isIsomorphic(s, t) << endl;
    return 0;
}