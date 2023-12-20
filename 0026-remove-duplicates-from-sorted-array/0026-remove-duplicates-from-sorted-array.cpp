class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        int count = 1;
        int curr = nums[0];
        int ind = 1;
        for(int i=1 ; i<n; i++)
        {
            if(nums[i] != curr)
            {
                count++;
                nums[ind] = nums[i];
                ind++;
                curr = nums[i];
            }
        }
        return count;
    }
};