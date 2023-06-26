class Solution 
{
public:
    int reverse(int x) 
    {
        if(x == INT_MIN || x == INT_MAX)
            return 0;
        
        int ans = 0;
        int temp = abs(x);
        
        while(temp!=0)
        {
            if(ans>INT_MAX/10)
                return 0;
            
            ans = ans*10 + temp%10;
            temp = temp/10;
        }
        if(x<0)
            ans = ans*-1;
        return ans;
        
    }
};