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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> levelAvgs;
        if(!root)
            return levelAvgs;
        queue<TreeNode *> toVisitQueue;
        TreeNode * currNode;
        toVisitQueue.push(root);

        while(!toVisitQueue.empty())
        {
            int queueSize = toVisitQueue.size();
            double sum = 0;
            for(int i = 0; i < queueSize; ++i)
            {
                currNode = toVisitQueue.front();
                sum += currNode->val;
                if(currNode->left) toVisitQueue.push(currNode->left);
                if(currNode->right) toVisitQueue.push(currNode->right);
                toVisitQueue.pop();
            }

            levelAvgs.push_back(sum / queueSize);
        }

        return levelAvgs;
    }
};