class Solution 
{
public:
    int numMusicPlaylists(int n, int goal, int k) 
    {
        const int mod = 1e9 + 7;
        vector dp(goal + 1, vector<long>(n + 1, -1));

        function<long(int, int)> numberOfPlaylists = [&](int i, int j) -> long 
        {
            if (i == 0 && j == 0) 
            {
                return 1LL;
            }
            if (i == 0 || j == 0) 
            {
                return 0LL;
            }
            if (dp[i][j] != -1) 
            {
                return dp[i][j];
            }
            
            dp[i][j] = (numberOfPlaylists(i - 1, j - 1) * (n - j + 1)) % mod;
            if (j > k) 
            {
                dp[i][j] += (numberOfPlaylists(i - 1, j) * (j - k)) % mod;
                dp[i][j] %= mod;
            }
            return dp[i][j];
        };

        return numberOfPlaylists(goal, n);
    }
};