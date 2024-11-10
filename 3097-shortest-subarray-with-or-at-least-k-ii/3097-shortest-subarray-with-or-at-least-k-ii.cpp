class Solution 
{
public:
    void updateBitCounts(vector<int>& bitCounts, int num, int delta) 
    {
        for(int i = 0; i < 32; i++) 
        {
            if((num >> i) & 1) 
                bitCounts[i] += delta;
        }
    }

    int convertBitCountsToNumber(const vector<int>& bitCounts)
    {
        int ans = 0;
        for(int i = 0; i < 32; i++) 
        {
            if(bitCounts[i] != 0) 
                ans |= 1 << i;
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
        int minSize = INT_MAX;
        int windowStart = 0;
        int windowEnd = 0;
        vector<int> bitCounts(32, 0);

        while(windowEnd < nums.size()) 
        {
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            while(windowStart <= windowEnd && convertBitCountsToNumber(bitCounts) >= k) 
            {
                minSize = min(minSize, windowEnd - windowStart + 1);
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }
            windowEnd++;
        }
        return minSize == INT_MAX ? -1 : minSize;
    }
};