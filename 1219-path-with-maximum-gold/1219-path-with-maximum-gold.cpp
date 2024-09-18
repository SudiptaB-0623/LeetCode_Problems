class Solution 
{
public:
    int maxGold(int row, int col, vector<vector<int>> &grid, int sum)
    {
        bool movesDone = true;
        int left = 0, right = 0, up = 0, down = 0;
        int curr = grid[row][col];  
        
        if(col>0 && grid[row][col-1]!=0)
        {
            grid[row][col] = 0;
            left = maxGold(row, col-1, grid, sum+curr);
            grid[row][col] = curr;
            movesDone = false;
        }
        if(col<grid[0].size()-1 && grid[row][col+1]!=0)
        {
            grid[row][col] = 0;
            right = maxGold(row, col+1, grid, sum+curr);
            grid[row][col] = curr;
            movesDone = false;
        }
        if(row>0 && grid[row-1][col]!=0)
        {
            grid[row][col] = 0;
            up = maxGold(row-1, col, grid, sum+curr);
            grid[row][col] = curr;
            movesDone = false;
        }
        if(row<grid.size()-1 && grid[row+1][col]!=0)
        {
            grid[row][col] = 0;
            down = maxGold(row+1, col, grid, sum+curr);
            grid[row][col] = curr;
            movesDone = false;
        }
        
        if(movesDone)
            return sum+curr;
        
        return max(max(left, right), max(up, down));
    }
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] != 0)
                {
                    ans = max(ans, maxGold(i, j, grid, 0));
                }
            }
        }
        
        return ans;
    }
};