#include <algorithm>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//Each node needs to compare the maximum of its left tree, right tree, and path going from the left tree to the right tree through the root node.
class Solution {
public:
    int maxPathSumCleaner(TreeNode * root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        
        return maxSum;
    }

    int dfs(TreeNode * root, int &maxSum)
    {
        if(!root)
            return 0;
        
        int leftMax = max(0, dfs(root->left, maxSum));
        int rightMax = max(0, dfs(root->right, maxSum));
        maxSum = max(maxSum, leftMax + root->val + rightMax);
        return root->val + max(leftMax, rightMax);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int maxLeftBranch, maxRightBranch, maxLeftPath, maxRightPath;

        calcMaxBranchAndPath(root->left, maxLeftBranch, maxLeftPath);
        calcMaxBranchAndPath(root->right, maxRightBranch, maxRightPath);

        return max({(root->left) ? maxLeftPath : INT_MIN,
                 maxLeftBranch + root->val + maxRightBranch,
                 (root->right) ? maxRightPath : INT_MIN,
                  root->val,
                  root->val + maxRightBranch,
                  root->val + maxLeftBranch});
    }

    void calcMaxBranchAndPath(TreeNode * root, int &maxBranch, int &maxPath)
    {
        int maxLeftBranch, maxRightBranch, maxLeftPath, maxRightPath;

        if(!root)
        {
            maxBranch = 0;
            maxPath = 0;
            return;
        }

        calcMaxBranchAndPath(root->left, maxLeftBranch, maxLeftPath);
        calcMaxBranchAndPath(root->right, maxRightBranch, maxRightPath);
        maxBranch = max(root->val + max(maxLeftBranch, maxRightBranch), root->val);
        maxPath = max({(root->left) ? maxLeftPath : INT_MIN,
            maxLeftBranch + root->val + maxRightBranch,
            (root->right) ? maxRightPath : INT_MIN,
             root->val,
             root->val + maxRightBranch,
             root->val + maxLeftBranch});
    }
};