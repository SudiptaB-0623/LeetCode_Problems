class Solution 
{
public:
    int commonFactors(int a, int b) 
    {
        if(a>b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        
        int ans = 1;
        
        for(int i=2;i<=a;i++)
        {
            if(a%i == 0 && b%i == 0)
                ans++;
        }
        
        return ans;
    }
};