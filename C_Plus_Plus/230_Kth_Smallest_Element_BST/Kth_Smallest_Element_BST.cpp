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
    int kthSmallest(TreeNode* root, int k) {
        int index = 0;
        //Go left
        int kthValue = dFSearch(root->left, k, index);

        if(index == k)
            return kthValue;

        //Update index
        if(++index == k)
            return root->val;

        //Go right
        return dFSearch(root->right, k, index);
    }

    int dFSearch(TreeNode * root, int k, int &index)
    {
        if(!root)
            return 0;
        
        int kthValue = dFSearch(root->left, k, index);

        if(index == k)
            return kthValue;

        //Update index
        if(++index == k)
            return root->val;

        //Go right
        return dFSearch(root->right, k, index);        
    }
};