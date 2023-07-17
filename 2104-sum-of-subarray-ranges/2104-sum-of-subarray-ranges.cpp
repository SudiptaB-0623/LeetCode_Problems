class Solution 
{
public:
    long long subArrayRanges(vector<int>& nums) 
    {
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
                
                ans -= (long long)(right-mid)*(mid-left)*nums[mid];
            }
            if(right!=n)
                st.push(right);
        }
        for(int right = 0; right<=n ; right++)
        {
            while(st.empty()!=true && (right==n || nums[st.top()] <= nums[right]))
            {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                
                ans += (long long)(right-mid)*(mid-left)*nums[mid];
            }
            if(right!=n)
                st.push(right);
        }
        
        return ans;
    }
};