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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head->next == nullptr && n == 1)
                return head->next;
            
            ListNode dummy(0, head);
            ListNode * behind = &dummy;
            ListNode * forward = &dummy;

            for(int i = 0; i <= n; ++i) forward = forward->next;

            while(forward)
            {
                behind = behind->next;
                forward = forward->next;
            }
            ListNode * newNext = behind->next->next;
            delete behind->next;
            behind->next = newNext;
            return dummy.next;
        }
};

int main(int argc, char ** args)
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    sol.removeNthFromEnd(head, 2);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}