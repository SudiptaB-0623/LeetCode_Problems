class Solution 
{
public:
    bool isPowerOfFour(int n) 
    {
        if(n==1)
            return true;
        if(n<=0 || n%4!=0)
            return false;
       
        if(((n&(0x55555555))>0) && ((n&(n-1))==0))
            return true;
        else
            return false;
        
    }
};