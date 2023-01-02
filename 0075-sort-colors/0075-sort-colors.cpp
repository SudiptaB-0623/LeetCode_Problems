class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        for(int i=1;i<nums.size();i++)
        {
            for(int j=i-1,k=i;j>=0;j--,k--)
            {
                if(nums[j]>=nums[k])
                    swap(nums[j],nums[k]);
                else
                    break;
            }
        }
    }
};