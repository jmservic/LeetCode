 
 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode * sum = nullptr;
            ListNode * currPos = nullptr;
            int carry = 0;
            int tempSum = 0;
            while(l1 != nullptr || l2 != nullptr)
            {
                tempSum = carry;
                carry = 0;
                if(l1 != nullptr)
                {
                    tempSum += l1->val;
                    l1 = l1->next;
                }

                if(l2 != nullptr) 
                {
                    tempSum += l2->val;
                    l2 = l2->next;
                }
                
                if (tempSum > 9)
                {
                    carry = 1;
                    tempSum -= 10;
                }

                if(currPos != nullptr)
                {
                    currPos->next = new ListNode(tempSum);
                    currPos = currPos->next;
                } else
                {
                    sum = new ListNode(tempSum);
                    currPos = sum;
                }
                
            }

            if(carry == 1)
                currPos->next = new ListNode(carry);
            return sum;
        }
};