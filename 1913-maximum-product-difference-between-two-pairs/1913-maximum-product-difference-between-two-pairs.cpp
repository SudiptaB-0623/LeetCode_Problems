class Solution 
{
public:
    int maxProductDifference(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int size = nums.size();
        
        int ans = (nums[size-1]*nums[size-2])-(nums[0]*nums[1]);
        
        return ans;
    }
};