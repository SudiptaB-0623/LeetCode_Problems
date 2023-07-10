class Solution 
{
public:
    int sumWays(int ind, int target, vector<int> nums, map<pair<int, int>, int> &dp)
    {
        if(ind == 0)
        {
            if(target+nums[0]==0 && target-nums[0]==0)
                return 2;
            else if(target+nums[0]==0 || target-nums[0]==0)
                return 1;
            
            return 0;
        }
        
        if(dp.find({ind, target}) != dp.end())
            return dp[{ind, target}];
        
        int plus = sumWays(ind-1, target+nums[ind], nums, dp);
        int minus = sumWays(ind-1, target-nums[ind], nums, dp);
        
        return dp[{ind, target}] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        map<pair<int, int>, int> dp;
        return sumWays(n-1, target, nums, dp);
    }
};