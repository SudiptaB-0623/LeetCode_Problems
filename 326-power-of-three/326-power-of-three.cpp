class Solution 
{
public:
    bool isPowerOfThree(int n) 
    {
        if(n<=0)
            return false;
        double a = log10(n)/log10(3);
        if(a-int(a)==0)
            return true;
        else 
            return false;
    }
};