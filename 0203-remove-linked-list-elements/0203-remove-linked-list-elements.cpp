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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head==NULL)
            return head;
        
        ListNode *temp=head ;
        ListNode *flag=temp;
        
        while(temp!=NULL)
        {            
            if(temp->val==val)
            {                
                flag->next = temp->next;
                
                if(head==temp)
                {
                    flag=flag->next;
                    head=flag;
                }
                
                ListNode *todel = temp;
                temp=temp->next;
                
                delete todel;
                continue;
            }
            flag = temp;
            temp = temp->next;                                    
        }
        return head;
    }
};