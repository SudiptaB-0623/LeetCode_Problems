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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        int size = 0;
        vector<ListNode*> ans;
        
        ListNode *temp=head;
        
        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }
        
        temp = head;
        int part = size/k;
        int k2 =k;
        cout<<part<<endl;  
        while(temp!=NULL)
        {
            int count;
            
            if((size%k)!=0)        
            {
                count = part+1;                
            }
            else
            {
                count = part;
            }
            cout<<count<<"##   ";
            size = size - count;
            cout<<size<<"## ";
            
            ListNode *front = new ListNode();
            front->val = temp->val;
            front->next=NULL;
            temp=temp->next;
            ListNode *flag= front;
            count--;
            
            while(count!=0)
            {
                cout<<temp->val<<" ";
                ListNode *fresh = new ListNode();
                fresh->val = temp->val;
                fresh->next=NULL;
                
                temp=temp->next;
                
                flag->next=fresh;
                flag=flag->next;
                count--;
            }
            
            ans.push_back(front);
            cout<<endl;
            k--;
        }
        
        while(ans.size()<k2)
            ans.push_back(NULL);
        
        return ans;
    }
};