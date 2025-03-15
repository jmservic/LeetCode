#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> rightSide{root->val};
        CheckTree(root->left, rightSide, 2);
        CheckTree(root->right, rightSide, 2);
        return rightSide;
    }

    void CheckTree(TreeNode * root, vector<int> &rightView, int depth)
    {
        if(!root)
            return;
        
        if(rightView.size() < depth)
            rightView.push_back(root->val);
        else
            rightView[depth - 1] = root->val;
        
        CheckTree(root->left, rightView, depth + 1);
        CheckTree(root->right, rightView, depth + 1);
    }
};