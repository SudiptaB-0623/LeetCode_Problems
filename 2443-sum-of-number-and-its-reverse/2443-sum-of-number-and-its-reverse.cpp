class Solution 
{
public:
    bool sumOfNumberAndReverse(int num) 
    {
        for(int i = num ; i>=0; i--)
        {
            int rev = 0;
            int cpy = i;
            int j =10;
            
            while(cpy != 0)
            {                
                rev = (rev*j )+ (cpy%10);                
                cpy = cpy/10;           
                
            }
            
            if(i+rev == num)
            {                
                return true;
            }
        }
        return false;
    }
};