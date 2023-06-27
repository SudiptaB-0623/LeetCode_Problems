class Solution 
{
public:
    int paths(int a, int b, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(a==0 && b==0)
            return dp[a][b] = grid[a][b];
        
        if(a<0 || b<0)
            return INT_MAX;         //Since we need min sum, while comparison this path will never be considered
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        int left, up;
        if(paths(a, b-1, grid, dp) == INT_MAX)
            left = INT_MAX;
        else
            left = grid[a][b] + paths(a, b-1, grid, dp);
        if(paths(a-1, b, grid, dp) == INT_MAX)
            up = INT_MAX;
        else
            up = grid[a][b] + paths(a-1, b, grid, dp);
        
        return dp[a][b] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int a = grid.size();
        int b = grid[0].size();
        vector<vector<int>> dp(a, vector<int>(b, -1));
        return paths(a-1, b-1, grid, dp);
    }
};