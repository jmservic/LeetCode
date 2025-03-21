#include <limits>

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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        if((root->left && root->left->val >= root->val) ||
            (root->right && root->right->val <= root->val))
            return false;
        
        return isValidLeftBST(root->left, numeric_limits<int>::min(), (root->val != numeric_limits<int>::min()) ? root->val - 1 : root->val) 
            && isValidRightBST(root->right, (root->val != numeric_limits<int>::max()) ? root->val + 1 : root->val, numeric_limits<int>::max());
    }

    bool isValidLeftBST(TreeNode * root, int min, int max)
    {
        if(!root)
            return true;
        
        if((root->left && (root->left->val >= root->val || root->left->val < min)) ||
            (root->right && (root->right->val <= root->val || root->right->val > max)))
            return false; 
        
        min = (root->val < min) ? root->val : min;

        return isValidLeftBST(root->left, min, root->val) && isValidRightBST(root->right, root->val, max);
    }

    bool isValidRightBST(TreeNode * root, int min, int max)
    {
        if(!root)
            return true;
        
        if((root->left && (root->left->val >= root->val || root->left->val < min)) ||
            (root->right && (root->right->val <= root->val || root->right->val > max)))
            return false;
        
        max = (root->val > max) ? root->val : max;
        
        return isValidLeftBST(root->left, min, root->val) && isValidRightBST(root->right, root->val, max);

    }
};