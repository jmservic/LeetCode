#include <cstddef>

using namespace std;
class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;
    
        Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    
        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
    public:
        Node* connect(Node* root) {     
            if(!root)
                return root;

            PopulateNextRightPointer(root->right, NULL);
            PopulateNextRightPointer(root->left, root->right);
            
            root->next = NULL;
            return root;
        }

        void PopulateNextRightPointer(Node * left, Node * right)
        {
            if(!left)
                return;
            
            
            
            Node * childLeftRight = (left->right) ? left->right : FindRightNextNode(right);
            Node * childRightRight = FindRightNextNode(right);
            
            PopulateNextRightPointer(left->right, childRightRight);
            PopulateNextRightPointer(left->left, childLeftRight);    
            left->next = right;  
        }

        Node * FindRightNextNode(Node * start)
        {
            if(!start)
                return start;
            
            if(start->left)
                return start->left;
            else if(start->right)
                return start->right;
            else if(start->next)
            {
                return FindRightNextNode(start->next);
            }

            return NULL;
        }
};

int main(int argc, char ** args)
{
    return 0;
}