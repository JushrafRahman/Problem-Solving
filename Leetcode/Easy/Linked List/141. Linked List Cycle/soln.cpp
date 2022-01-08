class Solution
{
private:
    unordered_map<string,bool>vis;
    bool res = false;
public:
    bool hasCycle(ListNode *head)
    {
        //string loc = head;
        while(head != NULL)
        {
	    //next 4 lines will be used to cast pointer address to string
            const void * address = static_cast<const void*>(head); 
            stringstream ss;
            ss << address;
            string loc = ss.str();
            if(vis[loc] == false)
            {
                vis[loc] =true;
            }
            else
            {
                res = true;
                break;
            }
            head = head->next;
        }
        return res;

    }
}
;