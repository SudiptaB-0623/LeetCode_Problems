class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        
        for(int i=(2*n)-1; i>=0 ; i--)
        {
            int ind = i%n;
            if(i+1 == 2*n)
            {
                ans[ind] = -1;
                st.push(nums[ind]);
            }
            else
            {
                while(st.empty()!= true && st.top()<=nums[ind])
                    st.pop();
                if(st.empty())
                    ans[ind] = -1;
                else
                    ans[ind] = st.top();
                st.push(nums[ind]);
            }
        }
        
        return ans;
    }
};