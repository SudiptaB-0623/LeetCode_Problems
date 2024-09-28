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
class MyCircularDeque 
{
    node *head, *rear;
    int size;
    int maxCap;
public:
    MyCircularDeque(int k) 
    {
        head = NULL;
        rear = NULL;
        maxCap = k;
        size = 0;
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
            return false;
        
        if(head == NULL)
        {
            head = new node(value);
            rear = head;
        }
        else
        {
            node *temp = new node(value);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        
        size++;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
            return false;
        
        if(rear == NULL)
        {
            head = new node(value);
            rear = head;
        }
        else
        {
            node *temp = new node(value);
            temp->prev = rear;
            rear->next = temp;
            rear = temp;
        }
        
        size++;
        return true;
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
            return false;
        
        if(size == 1)
        {
            node *temp = head;
            head = NULL;
            rear = NULL;
            delete temp;
        }
        else
        {
            node *temp = head->next;
            delete head;
            head = temp;
        }
        
        size--;
        return true;
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
            return false;
        
        if(size == 1)
        {
            node *temp = head;
            head = NULL;
            rear = NULL;
            delete temp;
        }
        else
        {
            node *temp = rear->prev;
            delete rear;
            
            rear = temp;
        }
        
        size--;
        return true;
    }
    
    int getFront() 
    {
        if(isEmpty())
            return -1;
        
        return head->val;
    }
    
    int getRear() 
    {
        if(isEmpty())
            return -1;
        
        return rear->val;
    }
    
    bool isEmpty() 
    {
        if(size == 0)
            return true;
        
        return false;
    }
    
    bool isFull() 
    {
        if(size >= maxCap)
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */