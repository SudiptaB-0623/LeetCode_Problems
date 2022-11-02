/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode *slow = head->next, *fast = (head->next)->next;
        
        while(fast!=NULL && fast!=slow)
        {            
            slow = slow->next;
            if(fast->next==NULL)
                return NULL;
            fast = (fast->next)->next;
        }
        
        if(fast==NULL)
            return NULL;
        
        if(fast==head)
            return head;
        else
        {
            slow=head;
            while(fast!=slow)
            {            
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
};