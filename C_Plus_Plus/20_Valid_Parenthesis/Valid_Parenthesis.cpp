#include <string>
#include <stack>


using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;

        for (char c : s) {
            switch(c) 
            {
                case '(':
                case '{':
                case '[':
                    charStack.push(c);
                    break;
                case ')':
                    if (charStack.empty() || charStack.top() != '(')
                        return false;
                    else
                        charStack.pop();
                    break;
                case '}':
                    if (charStack.empty() || charStack.top() != '{')
                        return false;
                    else
                        charStack.pop();
                    break;
                case ']':
                    if (charStack.empty() || charStack.top() != '[')
                        return false;
                    else
                        charStack.pop();
                    break;
                defaut:
                    break;
            }
        }

        return charStack.empty();
    }
};

int main(int argc, char ** args)
{
    return 0;
}