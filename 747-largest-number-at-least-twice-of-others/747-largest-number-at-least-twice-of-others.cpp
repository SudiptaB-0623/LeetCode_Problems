class Solution 
{
public:
    int dominantIndex(vector<int>& nums) 
    {
        vector<int> nums2 = nums;
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]/2 >= nums[nums.size()-2])
        {
            vector<int> :: iterator it;
            it = find(nums2.begin(),nums2.end(),nums[nums.size()-1]);
            return it-nums2.begin();
        }
        else 
            return -1;
    }
};