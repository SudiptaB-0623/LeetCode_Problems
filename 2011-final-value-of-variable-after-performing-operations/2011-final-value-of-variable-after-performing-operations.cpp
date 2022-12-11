class Solution 
{
public:
    int finalValueAfterOperations(vector<string>& operations) 
    {
        int ans = 0;
        
        for(int i=0;i<operations.size();i++)
        {
             for(int j=0;j<operations[i].size();j++)
             {
                 if(operations[i][j]=='-')
                 {
                     ans = ans - 1;
                     break;
                 }
                 if(operations[i][j]=='+')
                 {
                     ans = ans + 1;
                     break;
                 }
             }
        }
        return ans;
    }
};