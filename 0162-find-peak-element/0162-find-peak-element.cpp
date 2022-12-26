class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        if(nums[1]<nums[0])
            return 0;
        if(nums[nums.size()-2]<nums[nums.size()-1])
            return nums.size()-1;
        for(int i=1,j=nums.size()-2;i<((nums.size()/2)+1);i++,j--)
        {
            if((nums[i]>nums[i-1])&&(nums[i]>nums[i+1]))
                return i;
            if((nums[j]>nums[j-1])&&(nums[j]>nums[j+1]))
                return j;
            
        }
        return 0;
    }
};