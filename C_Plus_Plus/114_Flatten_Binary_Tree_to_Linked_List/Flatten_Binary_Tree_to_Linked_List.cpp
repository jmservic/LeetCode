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
        void flatten(TreeNode* root) {
            if(!root)
                return;

            if(root->left)
            {
                TreeNode * temp = recursiveFlatten(root->left);
                temp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            recursiveFlatten(root->right);
        }

        TreeNode * recursiveFlatten(TreeNode * root)
        {
            if(!root)
                return nullptr;

            TreeNode * temp;
            if(root->left)
            {
                temp = recursiveFlatten(root->left);
                temp->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            temp = recursiveFlatten(root->right);

            return (temp) ? temp : root;            
        }

        void flattenNoExtaSpace(TreeNode * root) {
            TreeNode * currNode = root;

            while(currNode)
            {
                if(currNode->left)
                {
                    findRightMostNode(currNode->left)->right = currNode->right;
                    currNode->right = currNode->left;
                    currNode->left = nullptr;
                }
    
                currNode = currNode->right;
            }
        }

        TreeNode * findRightMostNode(TreeNode * root)
        {
            TreeNode * prev = nullptr;
            TreeNode * currNode = root;

            while(currNode)
            {
                prev = currNode;
                if(currNode->right)
                    currNode = currNode->right;
                else
                    currNode = currNode->left;
            }

            return prev;
        }
};

int main(int argc, char ** args)
{

    return 0;
}