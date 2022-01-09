class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     if(head == NULL)
     {
         return head;
     }
     ListNode *prev = new ListNode();
     ListNode *later = new ListNode();
     if(head->next != NULL)
     {
         prev = head;
         head = head->next;
         later = head->next;
         prev->next = NULL;
         while((prev!= NULL) && (head!=NULL)&&(later!=NULL))
         {
             head->next = prev;
             prev = head;
             head = later;
             later = later->next; 
         }
         head->next = prev;
     }
    return head;

        
    }
};