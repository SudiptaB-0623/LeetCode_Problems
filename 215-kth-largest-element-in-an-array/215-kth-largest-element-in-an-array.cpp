class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int val=nums.size();
        return nums[val-k];
    }
};