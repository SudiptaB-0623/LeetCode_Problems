class Solution 
{
public:
    int uniquePaths(int a, int b) 
    {
        vector<vector<int>> dp(a, vector<int>(b, -1));
        
        for(int i = 0; i<a ; i++)
        {
            for(int j = 0; j<b ; j++)
            {
                if(i==0 && j==0)
                    dp[i][j] = 1;
                else
                {
                    int left = 0;
                    int up = 0;
                    if(j>0)
                        left = dp[i][j-1];
                    if(i>0)
                        up = dp[i-1][j];
                    
                    dp[i][j] = left + up;
                }
            }
        }
        return dp[a-1][b-1];
    }
};