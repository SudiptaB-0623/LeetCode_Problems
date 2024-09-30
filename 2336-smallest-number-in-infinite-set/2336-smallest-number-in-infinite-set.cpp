class SmallestInfiniteSet 
{
    int count;
    map<int, int> mpp;
public:
    SmallestInfiniteSet() 
    {
        count = 1;        
    }
    
    int popSmallest() 
    {
        while(mpp.find(count) != mpp.end())
            count++;
        
        mpp[count]++;
        return count;
    }
    
    void addBack(int num) 
    {
        if(mpp.find(num) != mpp.end())
            mpp.erase(num);
        
        if(num < count)
            count = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */