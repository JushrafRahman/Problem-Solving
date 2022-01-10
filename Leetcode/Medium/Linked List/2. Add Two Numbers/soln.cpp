class Solution {
private:
string s1 = "";
string s2 = "";
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        s1 = find_str(l1);
        s2 = find_str(l2);
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1>len2)
        {
            do_pad(s2,len1-len2);
        }
        else if(len2>len1)
        {
            do_pad(s1,len2-len1);
        }
        string res = add_str(s1,s2);
        
        ListNode *prev = new ListNode(res[0]-'0'); //1st digit of result
        ListNode *head = prev;
        for(int i=1; i<res.length(); i++)
        {
            int num =res[i] - '0';
            ListNode *newnode = new ListNode(num);
            prev->next = newnode;
            prev = newnode; 
        }
        return head;
    }
    string add_str(string &s1,string &s2)
    {
        int carry = 0;
        string res="";
        for(int i=0; i<s1.length(); i++)
        {
            int a = s1[i]-'0';
            int b = s2[i]-'0';
            int sum = a+b+carry;
            if(sum>=10)
            {
                sum = sum-10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res+=to_string(sum);
        }
        if(carry)
        {
            res+="1";
        }
        return res;
    }
    void do_pad(string &str,int zeros)
    {
        while(zeros)
        {
            str+="0";
            zeros--;
        }
        
    }
    string find_str(ListNode *x)
    {
        string temp = "";
        while(x!=NULL)
        {
            int v = x->val;
            temp+=to_string(v);
            x = x->next;
        }
        return temp;
    }
};