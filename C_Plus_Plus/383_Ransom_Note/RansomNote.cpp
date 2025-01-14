#include <string>
#include <unordered_map>
#include <iostream>
#include <ios>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //return false if ransomNote is longer than magazine
        if(ransomNote.length() > magazine.length()) return false;

        unordered_map<char, int> map;

        //create the map set;
        for(char& letter : magazine)
        {
            auto it = map.find(letter);
            if(it != map.end())
                ++(it->second);
            else
                map.insert({letter, 1});
        }

        //compare the ransomNote to the letter occurences in magazine.
        for(char& letter : ransomNote)
        {
            auto it = map.find(letter);
            if(it == map.end())
                return false;
            else if(it->second > 0)
                --(it->second);
            else
                return false;
        }
        
        return true;
    }
};

int main(int argc, char** args)
{
    string ransomNote = "aa";
    string magazine = "aab";
    Solution sol;
    cout << boolalpha;
    cout << sol.canConstruct(ransomNote, magazine) << endl;
    return 0;
}