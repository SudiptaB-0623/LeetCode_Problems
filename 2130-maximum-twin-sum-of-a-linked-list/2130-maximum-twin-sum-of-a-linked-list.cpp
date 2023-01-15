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
    int pairSum(ListNode* head) 
    {
        ListNode *slow, *fast;
        vector<int> sum;
        int i=0;
        
        for(slow=head, fast=head;slow!=NULL;)
        {
            if(fast!=NULL)
            {
                sum.push_back(slow->val);
                slow=slow->next;
                fast=(fast->next)->next;
                i++;
            }
            else
            {
                i--;
                sum[i] += slow->val;
                slow = slow->next;
            }
        }
        
        return *max_element(sum.begin(),sum.end());
    }
};