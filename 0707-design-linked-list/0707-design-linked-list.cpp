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
class MyLinkedList 
{
    node *head;
    node *rear;
    int size;
public:
    
    MyLinkedList() 
    {
        head = NULL;
        rear = NULL;
        size = 0;
    }
    
    int get(int index) 
    {
        if(index >= size)
            return -1;
                
        node *temp = head;
        for(int i=0; i<index; i++)
            temp = temp->next;
        
        return temp->val;
    }
    
    void addAtHead(int val) 
    {
        node *temp = new node(val);
        if(head == NULL)
        {
            head = temp;
            rear = temp;
        }
        else
        {            
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        
        size++;
    }
    
    void addAtTail(int val) 
    {
        node *temp = new node(val);
        if(head == NULL)
        {
            head = temp;
            rear = temp;
        }
        else
        {            
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        
        size++;
    }
    
    void addAtIndex(int index, int val) 
    {
        if(index <= size)
        {
            node *temp = new node(val);
            if(head == NULL)
            {
                head = temp;
                rear = temp;
            }
            else if(index == size)
            {
                rear->next = temp;
                temp->prev = rear;
                rear = temp;
            }
            else if(index == 0)
            {
                temp->next = head;
                head->prev = temp;
                head = temp;
            }
            else
            {
                node *flag = head;
                for(int i=0; i<index; i++)
                    flag = flag->next;
                
                node *last = flag->prev;
                last->next = temp;
                temp->next = flag;
                flag->prev = temp;
                temp->prev = last;
            }
            size++;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(index<size)
        {
            if(size == 1)
            {
                head = NULL;
                rear = NULL;
            }            
            else
            {
                node *temp = head;
                for(int i=0; i<index; i++)
                    temp = temp->next;
                
                node *before = temp->prev;
                node *after = temp->next;
                if(before == NULL)
                {
                    after->prev = NULL;
                    temp->next = NULL;
                    head = after;
                }
                else if(after == NULL)
                {
                    before->next = NULL;
                    temp->prev = NULL;
                    rear = before;
                }
                else
                {
                    before->next = after;
                    after->prev = before;
                }
            }
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */