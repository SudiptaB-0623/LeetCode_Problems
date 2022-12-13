class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int temp=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                if(nums[i]>temp)
                {
                    temp = nums[i];
                    ans.push_back(temp);
                }
            }
        }
        
        return ans;
    }
};