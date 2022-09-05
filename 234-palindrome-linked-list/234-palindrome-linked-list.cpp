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
        int size=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            size++;
            temp=temp->next;
        }
        temp=head;
        vector<int> nums;
        for(int i=0;i<size/2;i++)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        if(size%2!=0)
        {
            temp=temp->next;
        }
        for(int i=(size/2)-1;i>=0;i--)
        {
            if(nums[i]==temp->val)
            {
                temp=temp->next;
            }
            else
                return false;
        }
        return true;
    }
};