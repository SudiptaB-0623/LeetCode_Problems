class Solution 
{
public:
    void dfs(int sr, int sc, vector<vector<int>> &ans, int currColor, int newColor, vector<vector<int>> &vis)
    {
        ans[sr][sc] = newColor;
        vis[sr][sc] = 1;
        int n = ans.size();
        int m = ans[0].size();
        
        if(sr-1>=0 && vis[sr-1][sc]==0 && ans[sr-1][sc]==currColor)
            dfs(sr-1, sc, ans, currColor, newColor, vis);
            
        if(sr+1<n && vis[sr+1][sc]==0 && ans[sr+1][sc]==currColor)
            dfs(sr+1, sc, ans, currColor, newColor, vis);
            
        if(sc-1>=0 && vis[sr][sc-1]==0 && ans[sr][sc-1]==currColor)
            dfs(sr, sc-1, ans, currColor, newColor, vis);
            
        if(sc+1<m && vis[sr][sc+1]==0 && ans[sr][sc+1]==currColor)
            dfs(sr, sc+1, ans, currColor, newColor, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans = image;
        int currColor = image[sr][sc];
        
        dfs(sr, sc, ans, currColor, color, vis);
        
        return ans;
    }
};