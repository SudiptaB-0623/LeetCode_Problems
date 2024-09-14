class Solution 
{
public:
    int longestSubarray(vector<int>& nums) 
    {
        int maxNum = 0;
        int maxSize = 0;
        int currStreak = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > maxNum)
            {
                maxNum = nums[i];
                maxSize = 1;
                currStreak = 1;
            }
            else if(nums[i] == maxNum)
            {
                currStreak++;
                if(currStreak > maxSize)
                    maxSize = currStreak;
            }
            else
            {
                currStreak = 0;
            }
        }
        
        return maxSize;
    }
};