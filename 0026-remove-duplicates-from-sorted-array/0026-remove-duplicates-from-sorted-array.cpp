class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int ans = 1;
        int curr = nums[0];
        int ind = 1;
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != curr)
            {
                ans++;
                nums[ind] = nums[i];
                ind++;
                curr = nums[i];
            }
        }
        return ans;
    }
};