#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        deque<TreeNode *> toVisitDeque;
        bool leftToRight = false; //next state
        toVisitDeque.push_back(root);

        while(!toVisitDeque.empty()) {
            int loops = toVisitDeque.size();
            vector<int> tempVec;

            for(int i = 0; i < loops; ++i){
                TreeNode * curr;
                if(leftToRight) {
                    curr = toVisitDeque.back();
                    toVisitDeque.pop_back();
                    if(curr->right) toVisitDeque.push_front(curr->right);
                    if(curr->left) toVisitDeque.push_front(curr->left);
                } else {
                    curr = toVisitDeque.front();
                    toVisitDeque.pop_front();
                    if(curr->left) toVisitDeque.push_back(curr->left);
                    if(curr->right) toVisitDeque.push_back(curr->right);
                }
                   
                tempVec.push_back(curr->val);
            }

            res.push_back(tempVec);
            leftToRight = !leftToRight;
        }

        return res;
    }
};

int main(int argc, char ** args) {
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution sol;
    sol.zigzagLevelOrder(root);

    return 0;
}