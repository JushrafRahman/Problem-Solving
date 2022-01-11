class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int beginn, int endd)
    {
        if(beginn == endd)
        {
            return head;
        }
        ListNode *left  = findptr(head,beginn);
        ListNode *right = findptr(head,endd);
        ListNode *preleft = NULL;
        if(beginn == 1) //if reverse starts from 1st node
        {
            head = right; //right will be the 1st node after reverse
        }
        else
        {
            preleft = findptr(head,beginn-1); //node before left
            preleft->next = right;
        }
        if(left->next != NULL)
        {
            ListNode *prev = left;
            ListNode *cur = left->next;

            left->next = right->next;

            while(cur!=right)
            {
                ListNode *later = cur->next;
                cur->next = prev;
                prev = cur;
                cur = later;
            }
            cur->next = prev;


        }
        return head;
    }

    ListNode* findptr(ListNode *head, int idx)
    {
        ListNode *block = head;
        int cur = 1;
        while(block!=NULL)
        {
            if(cur == idx)
            {
                break;
            }
            cur++;
            block = block->next;
        }
        return block;
    }
};
