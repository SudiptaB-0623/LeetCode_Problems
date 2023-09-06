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
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *odd = new ListNode(-1);
        ListNode *even = new ListNode(-1);
        ListNode *olast = odd, *elast = even;
        int count = 0;
        ListNode *temp = head;
        
        while(temp!=NULL)
        {
            count++;
            if(count%2 == 1)
            {
                olast->next = temp;
                olast = olast->next;
                temp = temp->next;
                olast->next = NULL;
            }
            else
            {
                elast->next = temp;
                elast = elast->next;
                temp = temp->next;
                elast->next = NULL;
            }          
        }
        head = odd->next;
        olast->next = even->next;
        
        return head;
    }
};