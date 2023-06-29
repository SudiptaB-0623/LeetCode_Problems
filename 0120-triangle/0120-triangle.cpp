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
        return minPath(0, 0, dp, triangle);
    }
};