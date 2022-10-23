class Solution 
{
public:
    int getSum(int a, int b) 
    {
        unsigned count;
               
        while(b != 0)
        {     
            count = a & b;            
            
            a = a ^ b;
            b = count << 1;
            
        }
        
        return a;
    }
};