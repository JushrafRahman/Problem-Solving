class Solution
{
private:
    ListNode *res = NULL;    
public:
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL)
        {
            return head;
        }
        ListNode *prev = new ListNode();
        ListNode *later = new ListNode();
        if(head->next != NULL)
        {
            ListNode *temp = head->next;
            head->next = NULL;
            recur(head,temp);
            return res;

        }
        else
        {
            return head;
        }


    }
    void recur(ListNode *prev,ListNode *cur)
    {
        ListNode *later = cur->next;
        cur->next = prev;
        if(later != NULL)
        {
            recur(cur,later);
        }
        else
        {
            res = cur;

        }


    }
};