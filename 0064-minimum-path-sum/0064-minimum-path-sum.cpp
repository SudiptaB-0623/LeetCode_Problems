class Solution 
{
public:
  
    int minPathSum(vector<vector<int>>& grid) 
    {
        int a = grid.size();
        int b = grid[0].size();
        vector<vector<int>> dp(a, vector<int>(b, -1));     
        
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(i==0 && j==0)
                     dp[0][0] = grid[0][0];
                else
                {
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0)
                        up = grid[i][j] + dp[i-1][j];
                    if(j>0)
                        left = grid[i][j] + dp[i][j-1];
                    
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        return dp[a-1][b-1];
    }
};