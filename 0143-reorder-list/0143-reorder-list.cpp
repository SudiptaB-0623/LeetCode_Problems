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
    void reorderList(ListNode* head) 
      {
        if(head->next==NULL || (head->next)->next==NULL)
            return;
        
        ListNode *temp=head, *start=NULL, *begin=NULL, *flag=NULL;
        
        int size = 0;
        
        while(temp!=0)
        {
            size++;
            temp=temp->next;
        }
        
        size = size/2;
        
        temp=head;
        
        for(int i=0;i<size;i++)
        {
            temp=temp->next;
        }
        
        start = temp->next;
        temp->next = NULL;
        
        while(start!=NULL)
        {
            temp=new ListNode;
            temp->val = start->val;
            
            if(begin==NULL)
            {
                begin=temp;
                temp->next = NULL;
            }
            else
            {
                temp->next=begin;
                begin = temp;
            }
            
            start = start->next;
        }
        
        temp=head;
        while(begin!=NULL)
        {
            flag=temp->next;
            temp->next=begin;
            begin=begin->next;
            (temp->next)->next=flag;
            temp=flag;
        }
        
        
        return ;
    }
};