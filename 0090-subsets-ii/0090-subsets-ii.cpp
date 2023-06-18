class Solution 
{
public:
    void pick_loop(int ind, vector<int> ds, vector<vector<int>> &ans, vector<int> &nums)
    {
        ans.push_back(ds);
        if(ind == nums.size())
            return;
        
        for(int i=ind; i<nums.size();i++)
        {
            if(i>ind && nums[i]==nums[i-1])
                continue;
            ds.push_back(nums[i]);
            pick_loop(i+1, ds, ans, nums);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds = {};
        
        pick_loop(0, ds, ans, nums);
        
        return ans;
    }
};