class Solution 
{
public:
    int findways(int ind, int target, vector<int> nums, vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(target==0 && nums[0]==0)
                return 2;
            if(target==0 || target==nums[0])
                return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1)
            return dp[ind][target];
        
        int notTake = findways(ind-1, target, nums, dp);
        int take = 0;
        if(nums[ind]<=target)
            take = findways(ind-1, target-nums[ind], nums, dp);
        
        return dp[ind][target] = (take+notTake);
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totSum = 0;
        int n = nums.size();
        for(int i=0; i<n ; i++)
            totSum += nums[i];
        
        if(totSum-target<0 || (totSum-target)%2!=0)
            return 0;        
        
        int d = (totSum-target)/2;
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        cout<<d<<endl;
        return findways(n-1, d, nums, dp);
    }
};