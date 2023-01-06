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
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        vector<vector<int>> allgrps;
        vector<int> group;
        
        ListNode *temp = head;
        
        for(int i=1,j=0;temp!=NULL;temp=temp->next)
        {            
            if(j<i)
            {
                group.push_back(temp->val);
                j++;
            }
            else
            {
                i++;
                j=1;
                allgrps.push_back(group);
                group.erase(group.begin(),group.end());
                group.push_back(temp->val);
            }            
        }
        allgrps.push_back(group);
        
        for(int i=0;i<allgrps.size();i++)
        {
            if(allgrps[i].size()%2==0)
                reverse(allgrps[i].begin(),allgrps[i].end());
        }
        
        temp=head;
        for(int i=0,j=0;temp!=NULL;temp=temp->next)
        {
            temp->val=allgrps[i][j];
            j++;
            if(j==allgrps[i].size())
            {
                j=0;
                i++;
            }
        }
        return head;
    }
};