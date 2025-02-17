#include <unordered_set>

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

using namespace std;

class Solution {
    public:
        bool hasCycle(ListNode *head) {

            //With hashset
            /*unordered_set<ListNode *> seen;
            auto curr = head;
            while(curr != nullptr)
            {
                if(seen.contains(curr))
                    return true;
                else
                {
                    seen.insert(curr);
                    curr = curr->next;
                }
            } */

            //With slow / fast pointer
            ListNode * first = head;
            ListNode * second = head;

            while(first->next != nullptr && first->next->next != nullptr)
            {
                first = first->next->next;
                second = second->next;

                if(first == second)
                    return true;
            }

            return false;
        }
};