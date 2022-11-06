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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        if(head->next==NULL)
            return head;
        
        int count = 0,flag=0;
        ListNode *temp = head, *front = NULL, *tail = NULL;
        
        while(temp!=NULL)
        {
            temp=temp->next;
            count++;            
        }
        //cout<<count;
        temp = head;        
        for(int i=1;(i<=count) && (temp!=NULL) ;i++)
        {            
            if(i==k)
            {                
                front = temp;
                flag++;
                //cout<<"here: i="<<i<<" "<<front->val<<endl;
            }
            if(i==(count-k)+1)
            {                
                tail = temp; 
                flag++;
                //cout<<"here2: i="<<i<<" "<<tail->val<<endl;
            }            
            if(flag>=2)
                break;
            temp = temp->next;
        }
        
        swap(front->val,tail->val);
                
        return head;
    }
};