class Solution 
{
public:
    int shortestSubarray(vector<int>& nums, int targetSum) 
    {
        int n = nums.size();
        vector<long long> prefixSums(n + 1, 0);
        deque<int> dq;

        for(int i = 1; i <= n; i++) 
            prefixSums[i] = prefixSums[i - 1] + nums[i - 1];       

        int ans = INT_MAX;

        for(int i = 0; i<=n; i++) 
        {            
            while(!dq.empty() && prefixSums[i] - prefixSums[dq.front()] >= targetSum) 
            {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && prefixSums[i] <= prefixSums[dq.back()]) 
                dq.pop_back();

            dq.push_back(i);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};