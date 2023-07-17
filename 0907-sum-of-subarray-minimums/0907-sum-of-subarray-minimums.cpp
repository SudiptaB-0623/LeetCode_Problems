class Solution 
{
public:
    int sumSubarrayMins(vector<int>& nums) 
    {
        int mod = 1e9 + 7;
        long long ans = 0;
        stack<int> st;
        int n = nums.size();
        
        for(int right = 0; right<=n ; right++)
        {
            while(st.empty()!=true && (right==n || nums[st.top()] >= nums[right]))
            {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                
                ans = (ans + (long long)(right-mid)*(mid-left)*nums[mid])%mod;
            }
            if(right!=n)
                st.push(right);
        }
        
        return ans;
    }
};