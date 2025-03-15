#include <deque>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Like I thought, way too slow!!
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (root->left == nullptr && root->right == nullptr))
            return nullptr;
        
        if(root == q || root == p) return root;


        bool leftContainsANode = isDescendant(root->left, p, q);
        bool rightContainsANode = isDescendant(root->right, p, q);

        if(leftContainsANode && rightContainsANode)
            return root;
        else if(leftContainsANode)
            return lowestCommonAncestor(root->left, p, q);
        else if(rightContainsANode)
            return lowestCommonAncestor(root->right, p, q);
        else
            return nullptr;
    }
    bool isDescendant(TreeNode * root, TreeNode* p, TreeNode* q) {
        if(!root)
            return false;
        if(root == p || root == q || root->left == p || root->right == p)
            return true;
        else
            return isDescendant(root->left, p, q) || isDescendant(root->right, p, q);
    }

    TreeNode * lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || (root->left == nullptr && root->right == nullptr))
            return nullptr;
        
        if(root == q || root == p) return root;

        deque<TreeNode *> nodesToFind{p, q};

        
        auto commonAncestor = CheckBranches(root->left, nodesToFind);

        if(nodesToFind.size() == 0)
            return commonAncestor;
        else if(nodesToFind.size() == 1)
            return root;
        else 
            return commonAncestor = CheckBranches(root->right, nodesToFind);
    }

    TreeNode * CheckBranches(TreeNode * root, deque<TreeNode *> &nodesToFind) {
        if(!root || nodesToFind.size() == 0)
            return nullptr;

        if(nodesToFind.size() == 2)
        {
            if(root == nodesToFind[0])
                nodesToFind.pop_front();
            else if(root == nodesToFind[1])
                nodesToFind.pop_back();

            auto commonAncestor = CheckBranches(root->left, nodesToFind);
            if(commonAncestor) return commonAncestor;

            commonAncestor = CheckBranches(root->right, nodesToFind);
            if(commonAncestor) return commonAncestor;

            return (nodesToFind.size() == 0)? root : nullptr;
        } else 
        {
            if(root == nodesToFind[0])
                nodesToFind.pop_back();
            CheckBranches(root->left, nodesToFind);
            CheckBranches(root->right, nodesToFind);
            return nullptr;
        }
    }

    TreeNode * lowestCommonAncestor3(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root || root == p || root == q) return root;
        auto l = lowestCommonAncestor3(root->left, p, q);
        auto r = lowestCommonAncestor3(root->right, p, q);
        if(l && r) return root;
        return (l) ? l : r;
    }
};

int main(int argc, char ** args) 
{

    return 0;
}