class Solution 
{
public:
    int maximum69Number (int num) 
    {
        vector<int> dig;
        
        int cpy = num;
        
        while(cpy!=0)
        {
            dig.push_back(cpy%10);
            cpy = cpy/10;    
        }
        for(int i = dig.size()-1;i>=0;i--)
        {
            if(dig[i]!=9)
            {
                dig[i]=9;
                break;
            }
        }
        for(int i = dig.size()-1;i>=0;i--)
        {
            cpy = (cpy*10)+dig[i];
        }
        
        return cpy;
    }
};