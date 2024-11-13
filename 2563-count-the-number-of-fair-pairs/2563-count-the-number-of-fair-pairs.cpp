class Solution 
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());
        return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
    }
    long long lower_bound(vector<int>& nums, int value) 
    {
        int left = 0;
        int right = nums.size() - 1;
        long long ans = 0;
        while (left < right) 
        {
            int sum = nums[left] + nums[right];            
            if (sum < value) 
            {
                ans += (right - left);
                left++;
            } 
            else 
            {                
                right--;
            }
        }
        return ans;
    }
};