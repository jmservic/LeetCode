#include <deque>
#include <forward_list>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    deque<int> nodeQueue;
// forward_list<int> nodes;
// forward_list<int>::const_iterator it;
// forward_list<int>::const_iterator nextIt;
public:
    BSTIterator(TreeNode* root) {
        CreateList(root);        
    /*    CreateList(root);
        nodes.push_front(-1);
        it = nodes.cbegin();
        nextIt = ++nodes.cbegin(); */
    }
    
    int next() {
        int val = nodeQueue.front();
        nodeQueue.pop_front();
        return val;
   /*     ++nextIt;
        return *(++it);    */
    }
    
    bool hasNext() {
        
        return nodeQueue.empty();
       // return nextIt != nodes.cend();
    }

    void CreateList(TreeNode * currNode)
    {
        if (!currNode)
            return;
        
        CreateList(currNode->left);
        nodeQueue.push_back(currNode->val);
        CreateList(currNode->right);
        // CreateList(currNode->right);        
        // nodes.push_front(currNode->val);
        // CreateList(currNode->left);    
    }
};