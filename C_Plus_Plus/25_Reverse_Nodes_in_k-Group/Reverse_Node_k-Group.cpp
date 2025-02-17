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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(k <= 1)
                return head;
            //create a dummy head
            ListNode dummy(0, head);
            ListNode * currNode = head;
            ListNode * prevNode = &dummy;
            ListNode * nextNode;
            do 
            {
                for(int i = 1; i < k; ++i)
                {
                    nextNode = currNode->next;
                    currNode->next = nextNode->next;
                    nextNode->next = prevNode->next;
                    prevNode->next = nextNode;                 
                }
                prevNode = currNode;
                currNode = currNode->next;

            } while(enoughLeftInList(currNode, k));

            //return dummy head->next
            return dummy.next;            
        }

        bool enoughLeftInList(ListNode* head, int k){
            int count = 0;
            while(count < k)
            {
                if(head == nullptr)
                    return false;
                ++count;
                head = head->next;
            }

            return true;
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
    sol.reverseKGroup(head, 2);

    ListNode * nextNode = head;
    while(nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete head;
        head = nextNode;
    }

    return 0;
}