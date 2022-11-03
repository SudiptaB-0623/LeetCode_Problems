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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL  || head->next==NULL || (head->next)->next==NULL)
            return head;
        
        ListNode *temp = head;
        int count = 1;
        
        while(temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        
        ListNode *curr = head, *tail = temp;
        
        for(int i=0;curr!=temp && (i<count/2);i++)
        {
            ListNode *flag = curr->next;
            curr->next = flag->next;
            flag->next = NULL;
            tail->next=flag;
            tail=tail->next;
            
            curr=curr->next;
        }
        
        return head;
    }
};