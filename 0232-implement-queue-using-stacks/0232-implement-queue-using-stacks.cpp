class MyQueue {
public:
    stack<int> inp;
    stack<int> out;
    MyQueue() 
    {
        
    }
    
    void push(int x) 
    {
        inp.push(x);
    }
    
    int pop() 
    {
        if(out.empty())
        {
            while(inp.empty()!=true)
            {
                out.push(inp.top());
                inp.pop();
            }
        }
        if(out.empty())
            return -1;
        
        int t = out.top();
        out.pop();
        return t;
    }
    
    int peek() 
    {
        if(out.empty())
        {
            while(inp.empty()!=true)
            {
                out.push(inp.top());
                inp.pop();
            }
        }
        if(out.empty())
            return -1;
        return out.top();
    }
    
    bool empty() 
    {
        if(out.empty() && inp.empty())
            return true;
        
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */