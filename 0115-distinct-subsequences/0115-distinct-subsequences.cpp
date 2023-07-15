class Solution 
{
public:
    int distinctSub(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
    {
        if(ind2<0)
            return 1;
        if(ind1<0)
            return 0;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        if(s[ind1] == t[ind2])
            return dp[ind1][ind2] = distinctSub(ind1-1, ind2-1, s, t, dp)+distinctSub(ind1-1, ind2, s, t, dp);
        else
            return dp[ind1][ind2] = distinctSub(ind1-1, ind2, s, t, dp);
    }
    int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        
        if(n<m)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return distinctSub(n-1, m-1, s, t, dp);
    }
};