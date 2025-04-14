#include <vector>
#include <unordered_map>

using namespace std;
// Definition for a Node.
class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;

        unordered_map<int, Node *> nodes;
        Node * rtnNode = CreateConnections(node, nodes);        
        return rtnNode;        
    }

    Node * CreateConnections(Node * protoType, unordered_map<int, Node *> &nodes)
    {
        Node * copy = new Node(protoType->val);
        nodes.emplace(copy->val, copy);

        for(Node * neighbor : protoType->neighbors)
        {
            if(nodes.contains(neighbor->val))
            {
                copy->neighbors.push_back(nodes.at(neighbor->val));
            } else 
            { //Create the neight and their connections
                copy->neighbors.push_back(CreateConnections(neighbor, nodes));
            }
        }

        return copy;
    }
};