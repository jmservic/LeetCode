
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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int leafNodes = 0;
        int depth = GetDepth(root->left);
        leafNodes = GetLeafNodeNum(root->left, depth, 1);
        if(leafNodes > 0)
            leafNodes += GetLeafNodeNum(root->right, depth, 1);

        return (depth > 0) ? (1 << depth) - 1 + leafNodes : 1;        
    }

    int GetDepth(TreeNode * start)
    {
        if(!start)
            return 0;

        int depth = 1;
        while(start->left)
        {
            ++depth;
            start = start->left;
        }
        
        return depth;
    }

    int GetLeafNodeNum(TreeNode * start, int depth, int currDepth)
    {
        if(!start || currDepth > depth)
            return 0;

        int leafNodes;
        if(currDepth < depth)
        {
            leafNodes = GetLeafNodeNum(start->left, depth, currDepth+1);
            if(leafNodes > 0) 
                leafNodes += GetLeafNodeNum(start->right, depth, currDepth+1);
        } else
            leafNodes = 1;

        return leafNodes;
    }
};