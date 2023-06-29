class Solution 
{
public:
    int minPath(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& triangle)
    {   
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(i == triangle.size()-1)
        {            
            return dp[i][j] = triangle[i][j];
        }
        
        int down = triangle[i][j] + minPath(i+1, j, dp, triangle);
        int diag = triangle[i][j] + minPath(i+1, j+1, dp, triangle);
        
        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j = n-1; j>=0; j--)
        {
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i = n-2; i>=0 ; i--)
        {
            for(int j = i; j>=0 ; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(down, diag);
            }
        }
        
        return dp[0][0];
    }
};