/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 */
//Floyd's cycle finding algo
class Solution { //o(1) space complexity
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool res = false;
        while((slow!= NULL) && (fast != NULL) && (fast->next!=NULL))
        {
            slow = slow->next; //will travel by one node
            fast = fast->next->next; //will travel by two nodes
            if(slow == fast) //at any point if they're equal
            {
                res = true; //cycle exists
                break;
            }
            
        }
        return res;
        
    }
};

/*
(create a node)ListNode *slow = new ListNode(); //new keyword is requesting space (of size ListNode) to the OS. If space available, it is allocated and slow is pointing to it
above soln alternate way :
ListNode *slow = NULL; //a pointer of type ListNode is initialized which is not pointing to anything
slow = head; //now it is pointing to the node, head was pointing
//head contains address of the storage it is poiting
//slow  = head means now slow contains that address
//so basically slow is now pointing to the same address head is pointing

*/