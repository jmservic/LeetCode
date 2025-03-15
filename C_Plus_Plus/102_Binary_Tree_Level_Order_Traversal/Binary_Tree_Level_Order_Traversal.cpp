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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode *> toVisitQueue;
        TreeNode * currNode;
        toVisitQueue.push(root);

        while(!toVisitQueue.empty())
        {
            int size = toVisitQueue.size();
            vector<int> levelTraverse;
            for(int i = 0; i < size; ++i)
            {
                currNode = toVisitQueue.front();
                toVisitQueue.pop();
                levelTraverse.push_back(currNode->val);
                if(currNode->left) toVisitQueue.push(currNode->left);
                if(currNode->right) toVisitQueue.push(currNode->right);   
            }
            result.push_back(levelTraverse);
        }

        return result;
    }
};