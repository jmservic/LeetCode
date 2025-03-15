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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        return sumNumbersRecursive(root->left, root->val) + sumNumbersRecursive(root->right, root->val);
    }

    int sumNumbersRecursive(TreeNode * root, int currPathValue)
    {
        if(!root)
            return false;
        
        currPathValue = currPathValue * 10 + root->val;

        if(!root->left && !root->right)
            return currPathValue;
            
        return sumNumbersRecursive(root->left, currPathValue) + sumNumbersRecursive(root->right, currPathValue);
    }
};