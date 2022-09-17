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
    ListNode* sortList(ListNode* head) 
    {
        ListNode *temp=head;
        vector<int> num;
        int s=0;
        
        while(temp!=NULL)
        {
            num.push_back(temp->val);
            temp=temp->next;
            s++;
        }
        temp=head;
        sort(num.begin(),num.end());
        
        for(int i=0;i<s;i++)
        {
            temp->val=num[i];
            temp=temp->next;
        }
        
        
        
        return head;
    }
};