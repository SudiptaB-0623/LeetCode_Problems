class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(1);
        ans.push_back(cur);
        
        if(numRows == 1)
            return ans;
        
        cur.push_back(1);
        ans.push_back(cur);
        
        if(numRows == 2)
            return ans;
        
        for(int i=3;i<=numRows;i++)
        {
            vector<int> now;
            for(int j=0;j<i;j++)
            {
                if(j==0 || j==(i-1))
                {
                    now.push_back(1);
                    continue;
                }
                
                now.push_back(ans[i-2][j]+ans[i-2][j-1]);
            }
            ans.push_back(now);
            
        }
        return ans;
        
    }
};