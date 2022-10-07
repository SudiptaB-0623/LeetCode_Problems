class Solution 
{
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==nums.size()-1)
                return nums[nums.size()-1];
            if(nums[i]==nums[i+1])
                i++;
            else
                return nums[i];
        }
        return 0;
    }
};