class Solution 
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
                        
        int ans = 0;
        
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]-points[i-1][0]>ans)
                ans = points[i][0]-points[i-1][0];
        }
        
        return ans;
    }
};