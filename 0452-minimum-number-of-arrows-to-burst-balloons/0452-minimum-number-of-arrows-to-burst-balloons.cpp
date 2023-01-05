class Solution 
{
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end());
        int lastshot = points[0][1];
        int ans = 1;
                                
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>lastshot)
            {
                ans++;
                lastshot = points[i][1];
            }
            lastshot = min(lastshot,points[i][1]);
        }
     
        
        return ans;
    }
};