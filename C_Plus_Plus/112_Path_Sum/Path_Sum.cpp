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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        
        if(!root->left && !root->right)
        {
            return root->val == targetSum;
        }
        
        if(calculatePathSum(root->left, targetSum, root->val))
            return true;
        else if(calculatePathSum(root->right, targetSum, root->val))
            return true;
        
        return false;
    }

    bool calculatePathSum(TreeNode * root, int targetSum, int currentSum)
    {
        if(!root)
            return false;

        currentSum += root->val;
        
        if(!root->left && !root->right)
        {
            return currentSum == targetSum;
        }

        if(calculatePathSum(root->left, targetSum, currentSum))
            return true;
        else if(calculatePathSum(root->right, targetSum, currentSum))
            return true;
        
        return false;
    }
};