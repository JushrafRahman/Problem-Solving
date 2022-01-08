class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        ListNode *prev = new ListNode();
        ListNode *cur = new ListNode();
        ListNode *later = new ListNode();
        prev = head;
        cur = head->next;
        if(cur!=NULL) 
        {
            //atleast 2 nodes in the list
            later = cur->next;
            prev->next = NULL; //or nullptr
            while(prev && cur && later)
            {
                cur->next = prev;
                prev = cur;
                cur = later;
                later = later->next;        
            }
            cur->next = prev;
            return cur;
            
        }
        return head;
        
    }
};