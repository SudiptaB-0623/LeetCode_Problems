class Solution 
{
public:
    string removeOuterParentheses(string s) 
    {
        string ans = "";
        stack<char> st;
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
                continue;
            }
            if(s[i] == '(')
                st.push(s[i]);
            else
                st.pop();
            
            if(!st.empty())
                ans += s[i];
        }
        
        return ans;
    }
};