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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode *temp=head;
        
        while(temp->next!=NULL )
        {
            if(temp->val==(temp->next)->val)
            {
                ListNode *flag=temp->next;
                temp->next=flag->next;
                               
                delete flag;
                continue;
            }
            temp=temp->next;
            if(temp==NULL)
                break;
        }
        
        return head;
    }
};