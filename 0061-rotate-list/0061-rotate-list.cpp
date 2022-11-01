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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL)
            return head;
        
        if(k==0 || head->next==NULL)
            return head;
        
        int len = 1;
        
        ListNode *last = head;
        
        while(last->next!=NULL)
        {
            last = last->next;
            len++;
        }
                        
        k = k%len;
        
        if(k==0)
            return head;
        
        last->next=head;
        
        for(int i=0;i<(len-k);i++)
            last=last->next;
        
        head=last->next;
        last->next=NULL;
        
        return head;
    }
};