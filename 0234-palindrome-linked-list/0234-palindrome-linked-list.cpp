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
    bool isPalindrome(ListNode* head) 
    {
        if(head->next == NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *prev = NULL, *curr = slow->next, *next = NULL;
        
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        slow->next = prev;
        fast = head;
        slow = slow->next;
        
        while(slow != NULL)
        {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};