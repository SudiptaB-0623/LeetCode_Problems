class LRUCache 
{
public:
    class node
    {
      public:
        int key;
        int val;
        node *prev;
        node *next;
        node(int key_, int val_)
        {
            key = key_;
            val = val_;
            next = NULL;
            prev = NULL;
        }        
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> mpp;
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *temp)
    {
        temp->next = head->next;
        temp->prev = head;
        head->next = temp;
        (temp->next)->prev = temp;
    }
    
    void deleteNode(node *temp)
    {
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
    }
    
    int get(int key_) 
    {
        if(mpp.find(key_) != mpp.end())
        {
            node *temp = mpp[key_];
            int value = temp->val;
            
            mpp.erase(key_);
            deleteNode(temp);
            
            addNode(temp);
            mpp[key_] = head->next;
            
            return value;
        }
        return -1;
    }
    
    void put(int key_, int value) 
    {
        if(mpp.find(key_) != mpp.end())
        {
            node *temp = mpp[key_];
            mpp.erase(key_);
            deleteNode(temp);
        }
        
        if(mpp.size() == cap)
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        node *temp = new node(key_, value);
        addNode(temp);
        mpp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */