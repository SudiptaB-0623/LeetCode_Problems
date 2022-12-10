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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
            return NULL;
        vector<int> lst;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==NULL)
                continue;
            
            ListNode *temp = lists[i];
            
            while(temp!=NULL)
            {
                lst.push_back(temp->val);
                temp=temp->next;
            }
        }
            
        if(lst.size()==0)
            return NULL;
            
        sort(lst.begin(),lst.end());
            
        ListNode *flag = new ListNode();
        flag->val=lst[0];
        flag->next=NULL;
        ListNode *head = flag;
            
        for(int i=1;i<lst.size();i++)
        {
            ListNode *temp = new ListNode();
            temp->val=lst[i];
            temp->next=NULL;
                
            flag->next=temp;
            flag=flag->next;
        } 
        return head;
            
    }       
        

};