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
        vector<int> dp(n, -1);
        
        for(int j = n-1; j>=0; j--)
        {
            dp[j] = triangle[n-1][j];
        }
        
        for(int i = n-2; i>=0 ; i--)
        {
            vector<int> temp(n, -1);
            for(int j = i; j>=0 ; j--)
            {
                int down = triangle[i][j] + dp[j];
                int diag = triangle[i][j] + dp[j+1];
                
                temp[j] = min(down, diag);
            }
            dp = temp;
        }
        
        return dp[0];
    }
};