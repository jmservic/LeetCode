 #include <unordered_map>
 
 //Definition for singly-linked list.
 struct Node {
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

using namespace std;

class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == nullptr)
                return head;
            
            unordered_map<Node *, Node *> nodeMap;
            Node * newHead;

            //Construct the head node
            newHead = new Node(head->val);
            nodeMap.insert({head, newHead});

            //Check the next and random pointers
            if(head->next)
            {
                if(!nodeMap.contains(head->next))
                {
                    Node * temp = new Node(head->next->val);
                    newHead->next = temp;
                    nodeMap.insert({head->next, temp});
                } else
                    newHead->next = nodeMap[head->next];
            }

            if(head->random)
            {
                if(!nodeMap.contains(head->random))
                {
                    Node * temp = new Node(head->random->val);
                    newHead->random = temp;
                    nodeMap.insert({head->random, temp});
                } else
                    newHead->random = nodeMap[head->random];
            }

            linkNode(newHead->next, head->next, nodeMap);

            return newHead;
        }

        void linkNode(Node* node, Node* refNode, unordered_map<Node *, Node *> &nodeMap)
        {
            if(node == nullptr)
                return;
            
            //Check the next and random pointers
            if(refNode->next)
            {
                if(!nodeMap.contains(refNode->next))
                {
                    Node * temp = new Node(refNode->next->val);
                    node->next = temp;
                    nodeMap.insert({refNode->next, temp});
                } else
                    node->next = nodeMap[refNode->next];
            }

            if(refNode->random)
            {
                if(!nodeMap.contains(refNode->random))
                {
                    Node * temp = new Node(refNode->random->val);
                    node->random = temp;
                    nodeMap.insert({refNode->random, temp});
                } else
                    node->random = nodeMap[refNode->random];
            }

            linkNode(node->next, refNode->next, nodeMap);
        }

        Node* copyRandomListNoMap(Node* head){
            if (head == nullptr)
                return head;
            
            //Construct the head node
            Node * newHead = new Node(head->val);
            Node * currNode = newHead;
            Node * refNode = head;

            while(refNode != nullptr)
            {
                if(refNode->next != nullptr){
                    Node * temp = findNode(refNode->next, newHead, head);
                    currNode->next = (temp == nullptr) ? new Node(refNode->next->val) : temp;
                }

                if(refNode->random != nullptr){
                    Node * temp = findNode(refNode->random, newHead, head);
                    currNode->random = (temp == nullptr) ? new Node(refNode->random->val) : temp;
                }

                currNode = currNode->next;
                refNode = refNode->next;
            }
            
            return newHead;
        }

        Node * findNode(Node * target, Node * newList, Node * refList)
        {
            while(newList != nullptr)
            {
                if(target == refList)
                    return newList;
                else if(target == refList->next)
                    return newList->next;
                else if(target == refList->random)
                    return newList->random;
                
                newList = newList->next;
                refList = refList->next;
            }

            return nullptr;
        }
};