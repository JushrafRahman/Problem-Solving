/* Formula :
meeting point = when slow and fast meets hence cycle exist
entry point(beginning node of cycle) = until head node equals slow node keep incrementing them.

  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) //cycle exist
            {
                while(head != slow)
                {
                    head = head->next;
                    slow = slow->next;
                }
             return head;
                
            }
            
            
        }
        return NULL;
    }
};