class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int j=0; j<n ; j++)
            dp[0][j] = matrix[0][j];
        
        for(int i = 1; i<n ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int up = matrix[i][j] + dp[i-1][j];
                int left = 1e9, right = 1e9;
                if(j-1>=0)
                    left = matrix[i][j] + dp[i-1][j-1];
                if(j+1<n)
                    right = matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up, min(left, right));
            }
            
        }
        
        
        for(int j=0; j<n ;j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};