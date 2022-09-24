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
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *temp=head, *flag=head->next;
        
        head=flag;
        temp->next=flag->next;
        head->next=temp;
        temp=head;
        flag=head->next;
        
        while(1)
        {
            if(flag==NULL || temp==NULL)
                break;
            if(flag->next!=nullptr)
            {
                temp=flag->next;
                if(temp->next!=NULL)
                {
                    flag->next=temp->next;
                    temp->next=(flag->next)->next;
                    (flag->next)->next=temp;
                    flag=flag->next;
                    temp=flag;
                    flag=flag->next;
                    //temp=temp->next;
                    //if(temp!=NULL)
                     //   flag=temp->next;
                    //cout<<flag->val<<endl;
                }
                else
                    break;
            }
            else
                break;
        }
        
        return head;
        
    }
};