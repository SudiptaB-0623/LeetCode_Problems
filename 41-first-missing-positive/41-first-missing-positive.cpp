class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int j;
        
        for(int i=0,j=1;i<nums.size();i++)
        {
            if(nums[i]<=0)
                continue;
            if(nums[i]<j)
                continue;
            
            if(nums[i]!=j)
                    return j;
            else
                j++;
        }
        
        if((nums[nums.size()-1]+1)<=0)
            return 1;
        return (nums[nums.size()-1]+1);
    }
};