#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<string> ops;
        string tempStr;
        int op1, op2;
        char opChar;
        for( int i = s.size() - 1; i >= 0; --i)
        {
            char c = s[i];
            switch(c)
            {
                case '(':
                    if(!tempStr.empty())
                    {
                        reverse(tempStr.begin(), tempStr.end());
                        ops.push(tempStr);
                        tempStr.clear();
                    }                    
                    evaluateParenthesis(ops);
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case ')':
                    if(!tempStr.empty())
                    {
                        reverse(tempStr.begin(), tempStr.end());
                        ops.push(tempStr);
                        tempStr.clear();
                    }
                    tempStr = c;
                    ops.push(tempStr);
                    tempStr.clear();
                    break;
                case ' ':
                    break;
                default:
                    tempStr.push_back(c);
                    break;
            }

        }

        if(!tempStr.empty())
        {
            reverse(tempStr.begin(), tempStr.end());
            ops.push(tempStr);
        }

        while (ops.size() > 1)
        {
            if(ops.top() == "-")
                {
                    op1 = 0;
                    opChar = ops.top()[0];
                    ops.pop();
                    op2 = stoi(ops.top());
                    ops.pop();
                } else 
                {
                    op1 = stoi(ops.top());
                    ops.pop();
                    opChar = ops.top()[0];
                    ops.pop();
                    op2 = stoi(ops.top());
                    ops.pop();
                }

            op1 = evaluate(op1, op2, opChar);
            ops.push(to_string(op1));
        }

        return stoi(ops.top());
    }

    void evaluateParenthesis(stack<string> &ops)
    {
        int op1, op2;
        char opChar;
        while (ops.size() > 1)
        {
            if(ops.top() == "-")
            {
                op1 = 0;
                opChar = ops.top()[0];
                ops.pop();
                op2 = stoi(ops.top());
                ops.pop();
            } else 
            {
                op1 = stoi(ops.top());
                ops.pop();
                opChar = ops.top()[0];
                ops.pop();
                if(opChar == ')')
                {
                    ops.push(to_string(op1));
                    return;
                }
                op2 = stoi(ops.top());
                ops.pop();
            }

            op1 = evaluate(op1, op2, opChar);
            
            if(ops.top() == ")")
            {
                ops.pop();
                ops.push(to_string(op1));
                return;               
            } else
                ops.push(to_string(op1));     
        }
    }

    int evaluate(int op1, int op2, char opChar)
    {
        switch(opChar)
        {
                case '+':
                    return op1 + op2;
                case '-':
                    return op1 - op2;
                case '*':
                    return op1 * op2;
                case '/':
                    return op1 / op2;
        }

        return 0;
    }
};

int main(int argc, char ** args)
{
    string s = "0-2147483647";
    Solution sol;
    sol.calculate(s);
    return 0;
}
