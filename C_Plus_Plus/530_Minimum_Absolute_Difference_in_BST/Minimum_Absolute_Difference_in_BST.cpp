#include <vector>
#include <stack>
#include <limits>
#include <cmath>
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
    int getMinimumDifference(TreeNode* root) { //This works for all... trees. I need to optimized for BST.
        int minimumDiff = numeric_limits<int>::max();
        vector<int> visited;
        stack<TreeNode *> toVisitStack;
        toVisitStack.push(root);
        while(!toVisitStack.empty()) {
            TreeNode * curr = toVisitStack.top();
            for(int val : visited) {
                int diff = abs(curr->val - val);
                if(diff < minimumDiff) minimumDiff = diff;
            }
            visited.push_back(curr->val);
            toVisitStack.pop();
            if(curr->left) toVisitStack.push(curr->left);
            if(curr->right) toVisitStack.push(curr->right);
        }

        return minimumDiff;
    }

    int getMinimumDifference2(TreeNode * root) {
        int minimumDiff = numeric_limits<int>::max();
        TreeNode * lastVisited = nullptr;
        MinimumDifference(root->left, lastVisited, minimumDiff);
        
        if(lastVisited)
            minimumDiff = min(minimumDiff, abs(root->val - lastVisited->val));
        
        lastVisited = root;

        MinimumDifference(root->right, lastVisited, minimumDiff);

        return minimumDiff;       
    }

    void MinimumDifference(TreeNode * root, TreeNode * &lastVisited, int &minimumDiff) {
        if(!root) return;

        MinimumDifference(root->left, lastVisited, minimumDiff);

        if(lastVisited)
            minimumDiff = min(minimumDiff, abs(root->val - lastVisited->val));
        
        lastVisited = root;

        MinimumDifference(root->right, lastVisited, minimumDiff);
    }
};

int main(int argc, char ** args) {
    TreeNode * root = new TreeNode(5, new TreeNode(4), new TreeNode(7));
    Solution sol;
    sol.getMinimumDifference2(root);

    return 0;
}