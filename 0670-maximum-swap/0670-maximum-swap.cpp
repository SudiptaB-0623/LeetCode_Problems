class Solution 
{
public:
    int maximumSwap(int num) 
    {
        string s = to_string(num);
        int n = s.size();
        int maxId = -1;
        int swapId1 = -1;
        int swapId2 = -1;
        
        for(int i=n-1; i>=0; i--)
        {
            if(maxId==-1 || s[i]>s[maxId])
                maxId = i;
            else if(s[i]<s[maxId])
            {
                swapId1 = i;
                swapId2 = maxId;
            }
        }
        
        if(swapId1!=-1 && swapId2!=-1)
            swap(s[swapId1], s[swapId2]);
        
        return stoi(s);
    }
};