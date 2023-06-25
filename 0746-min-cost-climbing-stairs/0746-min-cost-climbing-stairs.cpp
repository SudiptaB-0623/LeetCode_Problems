class Solution 
{
public:
    int jump(int ind, int ans, vector<int> &dp, vector<int> cost)
    {
        if(ind == 0)
        {
            ans = cost[0];
            dp[ind] = cost[0];
            return ans;
        }
        if(ind == 1)
        {
            ans = min(cost[1], cost[1]+cost[0]);
            dp[ind] = ans;
            return ans;
        }
        
        if(ind!=cost.size() && dp[ind]!= -1)
            return dp[ind];
        
        int left = jump(ind-1, ans, dp, cost);
        int right = jump(ind-2, ans, dp, cost);
        
        if(ind == cost.size())
            return min(left, right);
        else        
            return dp[ind] = min(left, right)+cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size(), -1);
        int ans = 0;
        
        ans = jump(cost.size(), ans, dp, cost);
        
        return ans;
    }
};