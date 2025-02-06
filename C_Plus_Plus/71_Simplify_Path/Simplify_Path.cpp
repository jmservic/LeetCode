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
                    processString(tempStr, pathElements);
                    break;
                default:
                    tempStr.push_back(c);
            }
        }

        if (!tempStr.empty())
        {
            processString(tempStr, pathElements);            
        }

        while (!pathElements.empty())
        {
            tempStr = (!tempStr.empty()) ? pathElements.top() + "/" + tempStr : pathElements.top();
            pathElements.pop();
        }

        return "/" + tempStr;
            
    }

    void processString(string &str, stack<string> &pathElements)
    {
        if(str.empty())
            return;
        else if (str == "..")
        {
            if(!pathElements.empty())
                pathElements.pop();
        } else if (str != ".")
        {
            pathElements.push(str);
        }

        str.clear();
    }

};

int main(int argc, char ** args)
{
    string path = "/home/";
    Solution sol;
    sol.simplifyPath(path);
    return 0;
}