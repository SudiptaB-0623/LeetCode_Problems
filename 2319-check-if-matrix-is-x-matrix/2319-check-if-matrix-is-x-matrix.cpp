class Solution 
{
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        for(int i=0,j=grid.size()-1;i<grid.size();i++,j--)
        {
            if(grid[i][i]==0 || grid[i][j]==0)
                    return false;
            for(int x=0;x<grid.size();x++)
            {                
                if(x!=i && x!=j)
                {
                    if(grid[i][x]!=0)
                        return false;
                }
            }
        }
        return true;
    }
};