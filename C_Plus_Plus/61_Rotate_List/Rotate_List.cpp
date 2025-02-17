struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            int count = 0;
            
            if(head == nullptr)
                return head;
            else
                ++count;
            
            ListNode * end = head;
            ListNode dummy(0, head);
            while(end->next != nullptr) 
            {
                ++count;
                end = end->next;
            }

            k %= count;
            if(k == 0) return head;
            
            ListNode * prev;
            ListNode * newHead = head;
            for(int i = 0; i < count - k; ++i)
            {
                prev = newHead;
                newHead = newHead->next;
            }
            end->next = head;
            dummy.next = newHead;
            prev->next = nullptr;            

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
    sol.rotateRight(head, 2);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}