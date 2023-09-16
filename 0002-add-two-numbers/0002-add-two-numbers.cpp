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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode *start = new ListNode(-1);
        ListNode *last = start;
        ListNode *ptr1 = l1, *ptr2 = l2;
        
        while(ptr1 != NULL && ptr2!=NULL)
        {
            int sum = ptr1->val + ptr2->val + carry;
            carry = sum/10;
            last->next = new ListNode(sum%10);
            last = last->next;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1 != NULL)
        {
            int sum = ptr1->val + carry;
            carry = sum/10;
            last->next = new ListNode(sum%10);
            last = last->next;
            
            ptr1 = ptr1->next;
        }
        
        while(ptr2!=NULL)
        {
            int sum = ptr2->val + carry;
            carry = sum/10;
            last->next = new ListNode(sum%10);
            last = last->next;
            
            ptr2 = ptr2->next;
        }
        if(carry != 0)
        {
            last->next = new ListNode(carry);
        }
        return start->next;
    }
};