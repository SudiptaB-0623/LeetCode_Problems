class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int begin = 0;
        int end = 0;

        unordered_map<int, int> numToIndex;

        while(end < n) 
        {
            int curr = nums[end];
            int lastOccurrence = (numToIndex.count(curr) ? numToIndex[curr] : -1);

            while(begin <= lastOccurrence || end - begin + 1 > k) 
            {
                sum -= nums[begin];
                begin++;
            }
            numToIndex[curr] = end;
            sum += nums[end];
            if(end - begin + 1 == k)
                ans = max(ans, sum);
            end++;
        }
        return ans;
    }
};