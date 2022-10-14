class Solution 
{
public:
    int smallestEvenMultiple(int n) 
    {        
        for(int i = 1;;i++)
        {            
            if(((n*i)&1) == 0)
                return n*i;
        }
    }
};