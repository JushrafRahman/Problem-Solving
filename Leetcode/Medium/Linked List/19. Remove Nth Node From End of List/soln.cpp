class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int totnodes = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            totnodes++;
            temp = temp->next;
        }
        int rem  = totnodes - n;
        if(rem == 0)
        {
            head = head->next;
        }
        else
        {
            int cur = 1;
            temp = head;
            while(temp!= NULL)
            {
                if(cur == rem)
                {
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
                cur++;
            }
        }
        return head;
    }
};