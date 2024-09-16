class Solution 
{
public:
    void recur(int n, map<int, int> mpp, vector<vector<int>> &ans, vector<int> ds)
    {
        if(ds.size() == n)
        {
            ans.push_back(ds);
            return;
        }
        for(auto it : mpp)
        {
            if(it.second > 0)
            {
                ds.push_back(it.first);
                mpp[it.first]--;
                recur(n, mpp, ans, ds);
                mpp[it.first]++;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        map<int, int> mpp;
        vector<int> ds;
        
        for(int i=0; i<nums.size(); i++)
            mpp[nums[i]]++;
        
        recur(nums.size(), mpp, ans, ds);
        
        return ans;
    }
};