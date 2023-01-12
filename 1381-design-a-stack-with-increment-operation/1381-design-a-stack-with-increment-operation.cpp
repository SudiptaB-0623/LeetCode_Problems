class CustomStack 
{
public:
    int msize;
    vector<int> vec;
    CustomStack(int maxSize) 
    {
        msize = maxSize;
    }
    
    void push(int x) 
    {
        if(vec.size()!=msize)
            vec.push_back(x);
    }
    
    int pop() 
    {
        if(vec.size()==0)
            return -1;
        
        int x = *(vec.end()-1);
        vec.pop_back();
        return x;
    }
    
    void increment(int k, int val) 
    {
        for(int i=0;i<k && i<vec.size();i++)
            vec[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */