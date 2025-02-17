struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            if(head == nullptr || x <= -100)
                return head;
            
            ListNode dummy(0, head);
            ListNode * prev = head;
            ListNode * start = head;
            ListNode * insert;
            if(dummy.next->val >= x)
            {
                while(start && start->val >= x)
                {
                    prev = start;
                    start = start->next;
                }

                if (start)
                {
                    prev->next = start->next;
                    start->next = dummy.next;
                    dummy.next = start;
                }

                start = prev->next;
                insert = dummy.next;
            } else 
            {
                while(start && start->val < x)
                {
                    prev = start;
                    start = start->next;
                }

                insert = prev;
            }

            while(start)
            {
                if(start->val < x)
                {
                    prev->next = start->next;
                    start->next = insert->next;
                    insert->next = start;
                    insert = start;
                    start = prev->next;                    
                } else 
                {
                    prev = start;
                    start = start->next;
                }
            }


            return dummy.next;
        }
};


int main(int argc, char ** args)
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(1);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(5);
    //head->next->next->next->next->next = new ListNode(2);

    Solution sol;
    sol.partition(head, 2);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}