class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> st;
        vector<int> left(n), right(n);
        
        for(int i=0 ; i<n ; i++)
        {
            if(st.empty())
            {
                left[i] = -1;
            }
            else
            {
                while(st.empty()!=true && heights[st.top()]>=heights[i])
                    st.pop();
                
                if(st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        st = {};
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(st.empty())
            {
                right[i] = n;
            }
            else
            {
                while(st.empty()!=true && heights[st.top()]>=heights[i])
                    st.pop();
                
                if(st.empty())
                    right[i] = n;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        int maxi = 0;
        for(int i=0; i<n ; i++)
        {
            int curr = heights[i]*(right[i]-left[i]-1);
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};