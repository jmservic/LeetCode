#include <string>
#include <algorithm>
#include <iostream>
#include <ios>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int map[26] = {0};
        for_each(s.cbegin(), s.cend(), [&map](char c){++map[c - 'a'];});

        for(char c : t)
        {
            if(map[c - 'a'] == 0)
                return false;
            --map[c - 'a'];
        }

        return true;
    }
};


int main(int argc, char ** args)
{
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << boolalpha << sol.isAnagram(s,t) << endl;
    return 0;
}