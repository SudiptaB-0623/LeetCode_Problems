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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        vector<int> a,b,ans;
        
        ListNode *temp = l1;
        
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        
        temp = l2;
        while(temp!=NULL)
        {
            b.push_back(temp->val);
            temp=temp->next;
        }
        
        
        if(a.size()>b.size())
        {
            while(a.size()!=b.size())
            {
                b.insert(b.begin(),0);
            }
        }            
        else if(a.size()<b.size())
        {
            while(a.size()!=b.size())
            {
                a.insert(a.begin(),0);
            }
        } 
        
        int carry =0;
        for(int i=0,j=a.size()-1,k=b.size()-1;i<a.size();i++,j--,k--)
        {
            int sum = a[j]+b[k]+carry;
            
            if(sum>9)
            {
                sum = sum%10;
                carry = 1;
            }
            else
                carry=0;
            
            ans.push_back(sum);
        }
        
        if(carry == 1)
            ans.push_back(1);
        
        ListNode *flag = new ListNode();
        flag->val = ans[0];
        flag->next = NULL;
        temp = flag;
        
        for(int i=1;i<ans.size();i++)
        {
            ListNode *flag = new ListNode();
            flag->val = ans[i];
            flag->next = temp;
            
            temp = flag;
        }
        
        return temp;
    }
};