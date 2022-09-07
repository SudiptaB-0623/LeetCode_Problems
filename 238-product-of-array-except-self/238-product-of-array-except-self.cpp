class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans;
        ans.push_back(1);
        int val=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            ans.push_back(val);
            val=val*nums[i];
        }
        val=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            ans[i]=ans[i]*val;
            val=val*nums[i];
        }
        
        return ans;
    }
};