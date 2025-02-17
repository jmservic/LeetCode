 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if(list1 == nullptr && list2 == nullptr)
                return nullptr;
            else if(list1 == nullptr)
                return list2;
            else if(list2 == nullptr)
                return list1;

            ListNode * head;
            if(list1->val <= list2->val)
            {
                head = list1;
                list1 = list1->next;
            } else 
            {
                head = list2;
                list2 = list2->next;
            }

            ListNode * currNode = head;
            while(list1 != nullptr || list2 != nullptr)
            {
                if(list1 != nullptr && list2 != nullptr)
                {
                    if(list1->val <= list2->val)
                    {
                        currNode->next = list1;
                        list1 = list1->next;
                    } else 
                    {
                        currNode->next = list2;
                        list2 = list2->next;
                    }
                } else if(list1 != nullptr)
                {
                    currNode->next = list1;
                    list1 = list1->next;
                } else 
                {
                    currNode->next = list2;
                    list2 = list2->next; 
                }

                currNode = currNode->next;
            }

            return head;
        }
};