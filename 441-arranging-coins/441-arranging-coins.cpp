class Solution 
{
public:
    int arrangeCoins(int n) 
    {
        if(n==1 || n==2)
            return 1;
        long long i=1,a=0;
        for(;a+i<=n;i++)
            a=a+i;
        
        
        return i-1;
        
    }
};