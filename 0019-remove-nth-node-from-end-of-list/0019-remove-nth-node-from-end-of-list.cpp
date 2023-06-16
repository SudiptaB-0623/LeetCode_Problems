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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int i = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            i++;
            temp = temp->next;
        }
        //cout<<i;
        if(i==n)
        {
            ListNode *flag = head;
            head = head->next;
            delete flag;
            return head;
        }
        
        temp = head;
        for(int j=1;j<i-n;j++)
            temp = temp->next;
        ListNode *flag = temp->next;
        temp->next = flag->next;
        delete flag;
        
        return head;
    }
};