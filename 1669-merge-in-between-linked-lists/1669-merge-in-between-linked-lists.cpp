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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode *temp = list1, *flag = list1, *tail = list2;
        
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        
        for(int i=1;i<=b;i++)
        {            
            if(i==a)
            {    
                flag = temp->next;
                temp->next=list2;
                if(a==b)
                {
                    tail->next = flag->next;
                    break;
                }
                temp = flag;                
                
                continue;
            }
            if(i==b)
            {
                tail->next = (temp->next)->next;
                continue;
            }
            
            temp=temp->next;
        }
        
        return list1;
    }
};