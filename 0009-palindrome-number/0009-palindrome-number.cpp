class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        if(x<0 || x==INT_MAX || x==INT_MIN)
            return false;
        
        int temp = x;
        int rev = 0;
        
        while(temp!=0)
        {
            if(rev>INT_MAX/10)
                return 0;
            
            rev = rev*10 + temp%10;
            temp = temp/10;
        }
        if(rev == x)
            return true;
        else 
            return false;
    }
};