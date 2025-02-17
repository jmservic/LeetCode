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
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == nullptr || head->next == nullptr)
                return head;
            
            ListNode dummy(0, head);
            ListNode * prev = &dummy;
            ListNode * curr = head;
            ListNode * nextUniqueVal;
            ListNode * deleteNode;
            
            
            while(curr)
            {
                nextUniqueVal = curr->next;
                int nodesToRemove = 0;

                while(nextUniqueVal && nextUniqueVal->val == curr->val)
                {
                    deleteNode = nextUniqueVal;
                    nextUniqueVal = nextUniqueVal->next;
                    delete deleteNode;
                    ++nodesToRemove;
                }

                if(nodesToRemove > 0)
                {
                    prev->next = nextUniqueVal;
                    delete curr;
                } else 
                {
                    prev = curr;
                }
                
                curr = nextUniqueVal;
            }

            return dummy.next;
        }
};

int main(int argc, char ** args)
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    Solution sol;
    sol.deleteDuplicates(head);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}