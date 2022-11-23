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
    int getDecimalValue(ListNode* head) 
    {
        vector<int> bin;
        
        ListNode *temp = head;
        
        while(temp!=NULL)
        {
            bin.push_back(temp->val);
            temp= temp->next;
        }
        
        int dec = 0;
        
        for(int i=bin.size()-1,j=0;i>=0;i--,j++)
        {
            dec += pow(2,j)*bin[i];
        }
        
        return dec;
    }
};