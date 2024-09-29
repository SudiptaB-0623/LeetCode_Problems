struct node
{
    int val;
    node *next;
    node *prev;
    
    node(int x)
    {
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};
class FrontMiddleBackQueue 
{
    node *head;
    node *rear;
    int size;
public:
    FrontMiddleBackQueue() 
    {
        head = NULL;
        rear = NULL;
        size = 0;
    }
    
    void pushFront(int val) 
    {
        if(size == 0)
        {
            head = new node(val);
            rear = head;
        }
        else
        {
            node *temp = new node(val);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }        
        size++;
    }
    
    void pushMiddle(int val) 
    {
        node *curr = new node(val);
        
        if(size == 0)
        {
            head = curr;
            rear = curr;
            
            size++;
            return;
        }
        if(size == 1)
        {
            head->prev = curr;
            curr->next = head;
            head = curr;
            
            size++;
            return;
        }
        int pos = size/2;
        node *temp = head;
        while(pos>0)
        {
            temp = temp->next;
            pos--;
        }        
        
        curr->prev = temp->prev;
        curr->next = temp;
        (temp->prev)->next = curr;
        temp->prev = curr;
        
        size++;
    }
    
    void pushBack(int val) 
    {
        if(size == 0)
        {
            head = new node(val);
            rear = head;
        }
        else
        {
            node *temp = new node(val);
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
        }
        size++;
    }
    
    int popFront() 
    {
        if(size == 0)
            return -1;
        
        int ans = head->val;
        
        if(size == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            node *temp = head;
            head = head->next;
            head->prev = NULL;
        }
        
        size--;
        return ans;        
    }
    
    int popMiddle() 
    {
        if(size == 0)
            return -1;
        
        // node *flag = head;
        // while(flag!=NULL)
        // {
        //     cout<<flag->val<<" ";
        //     flag = flag->next;
        // }
        // cout<<endl;
        
        if(size == 1)
        {
            int ans = head->val;
            
            head = NULL;
            rear = NULL;
            
            size--;
            return ans;
        }
        if(size == 2)
        {
            int ans = head->val;
            
            head = head->next;
            head->prev = NULL;
            
            size--;
            return ans;
        }
        else
        {
            int pos = (size%2 == 0) ? (size/2)-1 : size/2; 
            node *temp = head;
            while(pos>0)
            {
                temp = temp->next;
                pos--;
            }
            
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            
            size--;
            return temp->val;
        }
    }
    
    int popBack() 
    {
        if(size == 0)
            return -1;
        
        int ans = rear->val;
        
        if(size == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
        }
        
        size--;
        return ans;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */