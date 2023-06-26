class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        int curr = 0;
        
        while(curr<=high)
        {
            if(nums[curr] == 0)
            {
                swap(nums[low], nums[curr]);
                curr++;
                low++;
            }
            else if(nums[curr] == 2)
            {
                swap(nums[high], nums[curr]);
                high--;
            }
            else
                curr++;
        }
    }
};