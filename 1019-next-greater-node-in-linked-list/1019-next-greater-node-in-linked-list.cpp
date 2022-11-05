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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> ans;
        
        if(head->next==NULL)
        {
            ans.push_back(0);
            return ans;
        }
        ListNode *temp = head;
                
        while(temp->next!=NULL)
        {
            int flag = 0;
            ListNode *lar = temp->next;
            while(lar!=NULL)
            {
                if(lar->val>temp->val)
                {                    
                    ans.push_back(lar->val);
                    flag++;                    
                    break;
                }
                
                lar = lar->next;
            }
            if(flag==0)
            {                
                ans.push_back(0);
            }
            
            temp=temp->next;
        }
        ans.push_back(0);
        return ans;
    }
};