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
    int numComponents(ListNode* head, vector<int>& nums) 
    {
        int flag = 0;
        int ans = 0;
        ListNode *temp = head;
        
        while(temp!=NULL)
        {
            //cout<<temp->val<<endl;
            auto it = find(nums.begin(),nums.end(),temp->val);
            if(it==nums.end())
            {
                flag=0;
            }
            else
            {
                if(flag==1)
                {
                    temp=temp->next;
                    continue;
                }
                else
                {
                    flag=1;
                    ans++;
                }
            }
            
            temp=temp->next;
        }
        
        return ans;
        
    }
};