/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution 
{
public:
    Node *findEndChild(Node *head)
    {
        Node *flag = head;
        while(flag->next!=NULL)
            flag = flag->next;
        
        return flag;
    }
    Node* flatten(Node* head) 
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            if(temp->child != NULL)
            {
                Node *start = temp->child;
                Node *end = findEndChild(start);
                Node *connectTo = temp->next;
                
                temp->next = start;
                start->prev = temp;
                
                end->next = connectTo;
                if(connectTo!=NULL)
                    connectTo->prev = end;
                
                temp->child = NULL;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};