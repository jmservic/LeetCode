#include <string>
#include <stack>
#include <sstream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathElements;
        string tempStr;

        for (char c : path) {
            switch(c)
            {
                case '/':
                    break;
                default:
                    tempStr.push_back(c);
            }
        }

        if(!tempStr.empty())
        {
            
        }
    }
};