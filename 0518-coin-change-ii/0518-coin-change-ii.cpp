class Solution 
{
public:
    int findways(int ind, int target, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(target==0 || target%coins[0] == 0)
                return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
                
        int notTake = findways(ind-1, target, coins, dp);
        int take = 0;
        if(coins[ind]<=target)
            take = findways(ind, target-coins[ind], coins, dp);
            
        return dp[ind][target] = (take+notTake);
    }
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        
        return findways(n-1, amount, coins, dp);
    }
};