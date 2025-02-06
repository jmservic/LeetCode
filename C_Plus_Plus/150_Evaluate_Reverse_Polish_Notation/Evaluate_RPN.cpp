#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opStack;
        int op1, op2;
        
        for (string &token : tokens)
        {
            if(token == "+" || token == "-" || token == "*" || token == "/")
            {
                op2 = opStack.top();
                opStack.pop();
                op1 = opStack.top();
                opStack.pop();

               char operation = token[0];
               switch(operation)
               {
                case '+':
                    op1 += op2;
                    break;
                case '-':
                    op1 -= op2;
                    break;
                case '*':
                    op1 *= op2;
                    break;
                case '/':
                    op1 /= op2;
                    break;
                default:
                    break;
               }
               opStack.push(op1);
            } else 
            {
                opStack.push(stoi(token));
            }       
        }

        return opStack.top();
    }
};