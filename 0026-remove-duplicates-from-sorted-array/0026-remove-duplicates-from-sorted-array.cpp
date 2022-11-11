class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 1;
                       
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else
               ans.push_back(nums[i]); 
        }
        
        for(int i=0;i<ans.size();i++)
        {
            nums[i]=ans[i];
        }
        
        return ans.size();
    }
};