#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            auto it = inorder.cbegin();
            TreeNode * head = new TreeNode(*it);
            TreeNode * currNode = head;
            ++it;

            while(it != inorder.cend())
            {
                currNode->right = new TreeNode(*it);
                ++it;
                currNode = currNode->right;
            }

            //Rotate until we get the correct head node
            it = preorder.cbegin();
            while(head->val != *it)
            {
                TreeNode * temp = head->right;
                temp->left = head;
                head->right = nullptr;
                head = temp;
            }

            ++it;
            satisfyPreorder(head, it, preorder.cend());
            
         /*   while(it != preorder.cend() && !searchNodes.empty() && head->left)
            {
                currNode = searchNodes.front();
                searchNodes.pop();

                if(currNode->left)
                {
                    if(currNode->left->val == *it)
                    {
                        searchNodes.push(currNode->left);
                        ++it;
                    } else if(inLeftTree(currNode->left->left, *it))
                    {
                        while(currNode->left->val != *it)
                        {
                            //Rotate right
                            rotateRight(currNode);
                        }
                        searchNodes.push(currNode->left);
                        ++it;
                    }
                }

                if(currNode->right)
                {
                    if(currNode->right->val == *it)
                    {
                        searchNodes.push(currNode->right);
                        ++it;
                    } else if(inRightTree(currNode->right->right, *it))
                    {
                        while(currNode->right->val != *it)
                        {
                            //Rotate left
                            rotateLeft(currNode);
                        }
                        searchNodes.push(currNode->right);
                        ++it;
                    }
                }                
            }

            if(searchNodes.empty())
                searchNodes.push(head);
            
            while(it != preorder.cend() && !searchNodes.empty())
            {
                currNode = searchNodes.front();
                searchNodes.pop();

                if(currNode->left)
                {
                    if(currNode->left->val == *it)
                    {
                        searchNodes.push(currNode->left);
                        ++it;
                    } else if(inLeftTree(currNode->left->left, *it))
                    {
                        while(currNode->left->val != *it)
                        {
                            //Rotate right
                            rotateRight(currNode);
                        }
                        searchNodes.push(currNode->left);
                        ++it;
                    }
                }

                if(currNode->right)
                {
                    if(currNode->right->val == *it)
                    {
                        searchNodes.push(currNode->right);
                        ++it;
                    } else if(inRightTree(currNode->right->right, *it))
                    {
                        while(currNode->right->val != *it)
                        {
                            //Rotate left
                            rotateLeft(currNode);
                        }
                        searchNodes.push(currNode->right);
                        ++it;
                    }
                }   
            } */

            return head;            
        }

        void satisfyPreorder(TreeNode * head, vector<int>::const_iterator &it, vector<int>::const_iterator end)
        {
            if(!head)
                return;

            if(head->left)
            {
                //Get the correct left node
                while(head->left->val != *it)
                    rotateRight(head);

                ++it;

                //Satisfy preorder
                satisfyPreorder(head->left, it, end);
            }

            if(head->right)
            {
                while(head->right->val != *it)
                    rotateLeft(head);
            
                ++it;
                //Satisfy preorder
                satisfyPreorder(head->right, it, end);
            }
        }

        bool inLeftTree(TreeNode * head, int val)
        {
            while(head)
            {
                if(head->val == val)
                    return true;
                
                head = head->left;
            }
            
            return false;
        }

        bool inRightTree(TreeNode * head, int val)
        {
            while(head)
            {
                if(head->val == val)
                    return true;
                
                head = head->right;
            }
            
            return false;
        }
        
        void rotateRight(TreeNode * head)
        {
            if(head->left && head->left->left)
            {
                TreeNode * temp = head->left->left;
                temp->right = head->left;
                head->left->left = nullptr;
                head->left = temp;
            }
        }

        void rotateLeft(TreeNode * head)
        {
            if(head->right && head->right->right)
            {
                TreeNode * temp = head->right->right;
                temp->left = head->right;
                head->right->right = nullptr;
                head->right = temp;
            }
        }
};

int main(int argc, char ** args)
{
    vector<int> preorder = {1,4,2,3,6,5};
    vector<int> inorder = {1,2,3,4,5,6};
    Solution sol;
    sol.buildTree(preorder, inorder);
}