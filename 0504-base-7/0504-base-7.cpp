class Solution {
public:
    string convertToBase7(int num) 
    {                
        int x = abs(num);
        int res = 0, i=1;
        
        while(x!=0) 
        {
            res = res + (i * (x % 7));
            i = i * 10;            
            x=x/7;
        }
        
        if(num<0)
        {
            res =  res * (-1);
        }
        
        string str = to_string(res);
        
        return str;
    }
};