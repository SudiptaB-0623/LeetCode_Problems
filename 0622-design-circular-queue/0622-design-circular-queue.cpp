struct node
{
    int val;
    node *next;
    
    node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};
class MyCircularQueue 
{
    node *head, *rear;
    int size, maxCap;
public:
    MyCircularQueue(int k) 
    {
        head = NULL;
        rear = NULL;
        size = 0;
        maxCap = k;
    }
    
    bool enQueue(int value) 
    {
        if(isFull())
            return false;
        
        if(size == 0)
        {
            head = new node(value);
            rear = head;
        }
        else
        {
            node *temp = new node(value);
            rear->next = temp;
            rear = temp;
        }
        
        size++;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty())
            return false;
        
        if(size == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
        
        size--;
        return true;
    }
    
    int Front() 
    {
        if(isEmpty())
            return -1;
        
        return head->val;
    }
    
    int Rear() 
    {
        if(isEmpty())
            return -1;
        
        return rear->val;
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull() 
    {
        return size == maxCap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */