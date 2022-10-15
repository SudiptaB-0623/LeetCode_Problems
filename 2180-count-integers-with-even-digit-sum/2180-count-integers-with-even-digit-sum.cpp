class Solution 
{
public:
    int countEven(int num) 
    {
        int x=num,sum=0;
        
        while(x!=0)
        {
            sum= sum + (x%10);
            x=x/10;
        }
        if(sum%2==0)
            return num/2;
        else
            return (num-1)/2;
        
    }
};