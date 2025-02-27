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
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
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
            auto rit = postorder.rbegin();
            while(head->val != *rit)
            {
                TreeNode * temp = head->right;
                temp->left = head;
                head->right = nullptr;
                head = temp;
            }

            ++rit;
            satisfyPostorder(head, rit);

            return head;
        }

        void satisfyPostorder(TreeNode * head, reverse_iterator<vector<int>::iterator> &it)
        {
            if(!head)
                return;

            if(head->right)
            {
                while(head->right->val != *it)
                    rotateLeft(head);
                
                ++it;
                satisfyPostorder(head->right, it);
            }

            if(head->left)
            {
                while(head->left->val != *it)
                    rotateRight(head);
                
                ++it;
                satisfyPostorder(head->left, it);
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
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    Solution sol;
    sol.buildTree(inorder, postorder);
}