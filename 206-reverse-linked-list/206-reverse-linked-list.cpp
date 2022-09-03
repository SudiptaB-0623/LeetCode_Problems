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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL)
            return head;
        ListNode *temp=head->next;
        head->next=NULL;
        ListNode *temp2;
        
        while(temp!=NULL)
        {
            if(temp->next != NULL)
                temp2=temp->next;
            else
                temp2=NULL;
            temp->next=head;
            head=temp;
            temp=temp2;
        }
        
        return head;
    }
};