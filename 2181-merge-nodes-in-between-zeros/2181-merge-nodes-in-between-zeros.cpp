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
    ListNode* mergeNodes(ListNode* head) 
    {
        ListNode *temp=head->next, *flag=head, *tail=NULL;
        
        while(temp!=NULL)
        {
            if(temp->val!=0)
            {
                flag->val+=temp->val;
                
                flag->next=temp->next;
                
                ListNode *todel = temp;
                temp=temp->next;
                delete todel;
                continue;
            }
            else
            {
                
                tail=flag;
                flag=temp;
                if(temp->next==NULL)
                    break;
                temp=temp->next;
            }
        }
        
        tail->next=NULL;
        delete temp;
        
        return head;
    }
};