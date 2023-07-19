class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        
        for(int i=0 ; i<=n ; i++)
        {
            while(!st.empty() && (i==n || heights[i]<heights[st.top()]))
            {
                int right = -1, mid = -1, left = -1;                
                right = i;
                mid = st.top();
                st.pop();
                left = st.empty() ? -1 : st.top();
                
                int curr = heights[mid] * (right-left-1);
                ans = max(ans, curr);
            }
            st.push(i);
        }
        return ans;
    }
};