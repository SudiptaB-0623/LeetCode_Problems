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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow->next;
            fast= fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* merge(ListNode *left, ListNode *right)
    {
        ListNode *start = new ListNode(-1);
        ListNode *rear = start;
        ListNode *head1 = left;
        ListNode *head2 = right;
        
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val < head2->val)
            {
                rear->next = head1;
                head1 = head1->next;
            }
            else
            {
                rear->next = head2;
                head2 = head2->next;
            }
            
            rear = rear->next;
            rear->next = NULL;
        }
        
        if(head1 == NULL)
            rear->next = head2;
        if(head2 == NULL)
            rear->next = head1;
        
        return start->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *mid = findMid(head);
        
        ListNode *left = head;
        ListNode *right = mid->next;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        
        ListNode *ans = merge(left, right);
        
        return ans;
    }
};