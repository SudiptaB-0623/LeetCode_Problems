class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        long long a,b;
        
        for(a = sqrt(c);a>=0;a--)
        {
            b = sqrt(c - (a*a));
            
            if(((a*a)+(b*b))==c)
                return true;
        }
        return false;
    }
};