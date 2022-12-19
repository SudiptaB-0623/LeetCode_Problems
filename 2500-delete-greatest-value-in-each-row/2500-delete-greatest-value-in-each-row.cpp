class Solution 
{
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        int ans = 0;
        
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());
        }
        
        for(int i=0;i<grid[0].size();i++)
        {
            vector<int> temp;
            for(int j=0;j<grid.size();j++)
            {
                temp.push_back(grid[j][i]);
            }
            int max = *max_element(temp.begin(),temp.end());
            ans += max;
        }
        
        return ans;
    }
};