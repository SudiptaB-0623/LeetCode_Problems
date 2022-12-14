class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        int s = nums.size();
		sort(nums.begin(), nums.end());
		return max(nums[s - 1] * nums[s - 2] * nums[s - 3], nums[0] * nums[1] * nums[s - 1]);
    }
};