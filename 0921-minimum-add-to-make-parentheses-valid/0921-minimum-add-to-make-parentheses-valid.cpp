class Solution 
{
public:
    int minAddToMakeValid(string s) 
    {
        int n = s.size();
        if(n==0)
            return n;
        stack<char> st;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i]==')' && st.empty()==false)
                st.pop();
            else
                ans++;
        }
        
        return ans + st.size();
    }
};