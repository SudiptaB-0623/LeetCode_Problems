class Solution 
{
public:
    int heightChecker(vector<int>& heights) 
    {
        int ans=0;
        
        vector<int> cpy = heights;
        sort(cpy.begin(),cpy.end());
        
        for(int i=0;i<heights.size();i++)
        {
            if(cpy[i]!=heights[i])
                ans++;
        }
        
        return ans;
    }
};