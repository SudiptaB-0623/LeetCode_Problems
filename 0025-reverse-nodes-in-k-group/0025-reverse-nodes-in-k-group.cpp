/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:
    ListNode *rev(ListNode *head)
    {        
        ListNode *prev = NULL, *nex = NULL, *curr = head;
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        
        return prev;
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head, *pre = NULL;
                
        while(temp!=NULL)
        {
            ListNode *start = temp;
            int i = 1;
            for(;i<k && temp->next!=NULL;i++)
            {
                temp = temp->next;
            }
            if(i!=k)
                break;
            
            ListNode *flag = temp->next;
                        
            temp->next = NULL;
            
            ListNode *new_start = rev(start);
            
            start->next = flag;          
            
            if(start == head)
                head = temp;
            
            if(pre!=NULL)
                pre->next = new_start;
            
            pre = start;
            temp = flag;
        }
        return head;
    }
};