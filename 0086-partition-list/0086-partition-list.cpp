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
    ListNode* partition(ListNode* head, int x) 
    {
        if(head == NULL)
            return NULL;
        
        ListNode *small = new ListNode(-1);
        ListNode *slast = small;
        ListNode *big = new ListNode(-1);
        ListNode *blast = big;
                
        while(head != NULL)
        {
            if(head->val < x)
            {
                slast->next = head;
                head = head->next;
                slast = slast->next;
                slast->next = NULL;
            }
            else
            {
                blast->next = head;
                head = head->next;
                blast = blast->next;
                blast->next = NULL;
            }
        }
        slast->next = big->next;
        head = small->next;
        
        return head;
    }
};