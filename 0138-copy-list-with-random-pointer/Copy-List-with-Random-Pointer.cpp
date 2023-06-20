/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> mpp;
        Node *temp = head;
        
        while(temp!=NULL)
        {
            Node *copy = new Node(temp->val);
            mpp[temp] = copy;
            temp = temp->next;
        }
        
        temp = head;
        for(auto it : mpp)
        {
            Node *curr = it.first;
            Node *copy = it.second;
            
            if(curr->next!=NULL)
                copy->next = mpp[curr->next];
            else
                copy->next = NULL;
            
            if(curr->random!=NULL)
                copy->random = mpp[curr->random];
            else
                copy->random = NULL;
        }
        
        Node *ans = mpp[head];
        return ans;
    }
};
