class Solution 
{
public:
    int change(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(target%coins[0] == 0)
                return target/coins[0];
            else
                return 1e9 + 7;  
        }
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int notTake = change(ind-1, target, coins, dp);
        int take = 1e9 + 7;
        if(coins[ind] <= target)
            take = 1 + change(ind, target-coins[ind], coins, dp);
        
        return dp[ind][target] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0)
            return 0;
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = change(n-1, amount, coins, dp);
        
        
        if(ans >= 1e9+7)
            return -1;
        else
            return ans;
    }
};