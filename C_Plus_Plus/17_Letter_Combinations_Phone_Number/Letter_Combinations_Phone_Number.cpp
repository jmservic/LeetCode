#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<char> encodings[8] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r',  's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letterCombos;
        string temp;
        temp.reserve(digits.length());
        ConstructCombinations(digits, letterCombos, temp, 0);
        return letterCombos;
    }

    void ConstructCombinations(const string &digits, vector<string> &store, string &prefix, int index) {
        char digit = digits[index];
        
        for (char l : encodings[digit - '2']) 
        {
            prefix.push_back(l);
            if (index == digits.length() - 1) 
            {
                store.push_back(prefix);
            } else 
            {
                ConstructCombinations(digits, store, prefix, index + 1);
            }
            prefix.pop_back();
        }
    }
};