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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *before=head, *flag=head;
        int num=404;
        
        while(flag!=NULL)
        {
            
            if(flag->val==num)
            {
                
                ListNode *temp=flag;
                if(head==temp)
                    head=head->next;
                flag=flag->next;
                before->next=flag;
                delete temp;
                
                if(flag==head)
                    before=flag;
                if(flag==NULL)
                    break;
                continue;
            }
            if(flag->next!=NULL)
                if(flag->val == (flag->next)->val)
                {
                    num=flag->val;

                    if(head==flag)
                    {
                        head=(flag->next)->next;

                    }
                    ListNode *temp=flag,*temp2=flag->next;
                    flag=(flag->next)->next;
                    before->next=flag;
                    delete temp;
                    delete temp2;

                    if(flag==head)
                        before=flag;
                    if(flag==NULL)
                        break;
                    continue;
                }
            before=flag;
            flag=flag->next;
        }
        if(head!=NULL && num==head->val)
            return NULL;
        return head;
    }
};