class Solution 
{
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> left(n), right(n);
        
        for(int i=0 ; i<n ; i++)
        {
            if(st.empty() == true)
            {
                left[i] = -1;
                st.push(i);
            }
            else
            {
                while(st.empty()!=true && arr[st.top()]>arr[i])
                    st.pop();
                if(st.empty())
                    left[i] = -1;
                else
                    left[i] = st.top();
                st.push(i);
            }
        }
        
        st = {};
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(st.empty() == true)
            {
                right[i] = -1;
                st.push(i);
            }
            else
            {
                while(st.empty()!=true && arr[st.top()]>=arr[i])
                    st.pop();
                
                if(st.empty())
                    right[i] = -1;
                else
                    right[i] = st.top();
                st.push(i);
            }
        }
        
        long long int ans = 0;
        for(int i=0 ; i<n ; i++)
        {
            long long int l = (left[i] == -1) ? i+1 : i-left[i];
            long long int r = (right[i] == -1) ? n-i : right[i]-i;
            
            ans = (ans + (l*r)*arr[i])%mod;
        }
        
        return ans;
    }
};