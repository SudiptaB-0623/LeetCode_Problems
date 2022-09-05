class Solution 
{
public:
    int titleToNumber(string columnTitle) 
    {
        int ans=0;
        
        for(int i=columnTitle.length()-1,j=0;i>=0;i--,j++)
        {
            ans=ans+((columnTitle[i]-64)*pow(26,j));
        }
        
        return ans;
    }
};