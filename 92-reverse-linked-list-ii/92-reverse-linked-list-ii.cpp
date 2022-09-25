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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head->next==NULL)
        {
            return head;
        }
        if(left==right)
            return head;
        ListNode *temp=head, *flag=head, *trav=head, *stand=head ;
        
        for(int i=1;i<left;i++)
        {
            stand=flag;
            flag=flag->next;
        }
        for(int i=1;i<right;i++)
        {
            trav=trav->next;
        }
        
        while(1)
        {
            temp=flag->next;
            flag->next=trav->next;
            trav->next=flag;
            if(stand!=flag)
                stand->next=temp;
            else
            {
                head=temp;
                stand=temp;
            }
            flag=temp;
            if(flag==trav)
            {
                break;
            }
            
        }
        
        
        return head;
    }
};