class Solution 
{
public:
    bool isPowerOfTwo(int n) 
    {
        if(n == 1 || n==2)
            return true;
        
        if(n<=0 || n%2 == 1)
            return false;
                           
        if((n & (n-1)) == 0)
            return true;
        else
            return false;
    }
};
