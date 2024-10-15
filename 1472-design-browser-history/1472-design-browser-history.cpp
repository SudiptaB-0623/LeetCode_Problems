struct node
{
    string val;
    node *next;
    node *prev;
    
    node(string x)
    {
        this->val = x;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory 
{
    node *head;
    node *flag;
public:
    BrowserHistory(string homepage) 
    {
        head = new node(homepage);
        flag = head;
    }
    
    void visit(string url) 
    {
        node *temp = new node(url);
        flag->next = temp;
        temp->prev = flag;
        flag = flag->next;
    }
    
    string back(int steps) 
    {
        while(steps>0 && flag!=head)
        {
            steps--;
            flag = flag->prev;
        }
        
        return flag->val;
    }
    
    string forward(int steps) 
    {
        while(steps>0 && flag->next!=NULL)
        {
            steps--;
            flag = flag->next;
        }
        
        return flag->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */