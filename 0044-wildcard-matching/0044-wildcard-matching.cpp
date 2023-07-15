class Solution 
{
public:
    
    bool isMatch(string s, string p) 
    {
        int n = s.size();
        int m = p.size();
        
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0] = true;
        for(int j=1 ; j<=m ; j++)
        {
            int ind2 = j;
            while(ind2>0)
            {
                if(p[ind2-1] != '*')
                {
                    dp[0][j] = 0;
                    break;
                }
                ind2--;
            }
            if(ind2==0)
                dp[0][j] = 1;
        }
        
        for(int ind1=1; ind1<=n ; ind1++)
        {
            for(int ind2=1 ; ind2<=m ; ind2++)
            {
                if(s[ind1-1] == p[ind2-1]  || p[ind2-1] == '?')
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                else
                {
                    if(p[ind2-1] == '*')
                        dp[ind1][ind2] = dp[ind1][ind2-1] || dp[ind1-1][ind2];
                    else
                        dp[ind1][ind2] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};