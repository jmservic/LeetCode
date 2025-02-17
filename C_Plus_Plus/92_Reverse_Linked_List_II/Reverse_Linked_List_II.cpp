 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode * currNode = head;
            ListNode * prevNode = nullptr;
            int currPos = 1;

            //Get to the start of the swapping section.
            while(currPos < left)
            {
                prevNode = currNode;
                currNode = currNode->next;
                ++currPos;
            }

            currNode = swapNodes(prevNode, currNode, currPos, left, right);

            if(prevNode == nullptr)
                return currNode;

            return head;
        }

        ListNode* swapNodes(ListNode * prevNode, ListNode* node, int currPos, int left, int right)
        {
            int midNode = (right + left) / 2;
            if(currPos == midNode)
            {
                
                if((right - left) % 2 == 1)
                { //we have an even number of nodes
                    ListNode * nextNode = node->next;
                    node->next = nextNode->next;
                    nextNode->next = node;
                    if(prevNode != nullptr)
                        prevNode->next = nextNode;
                    else
                        return nextNode; 
                    
                }

                return node;
            } else 
            {
                ListNode * nodeBeforeSwapNode = swapNodes(node, node->next, currPos + 1, left, right);
                ListNode * swapNode = nodeBeforeSwapNode->next;
                ListNode * currNextNode = node->next;
                if(prevNode != nullptr)
                    prevNode->next = swapNode;
                node->next = swapNode->next;
                swapNode->next = currNextNode;
                nodeBeforeSwapNode->next = node;
                if(prevNode == nullptr)
                    return swapNode;
                else
                    return  (currPos == left) ? nullptr : node;               
            }
        }
};

int main(int argc, char ** args)
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    Solution sol;
    sol.reverseBetween(head, 2, 3);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}