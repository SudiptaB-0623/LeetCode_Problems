class Solution 
{
public:
    int minSwaps(string s) 
    {
        int unbalanced = 0;
        stack<int> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '[')
                st.push(s[i]);
            else if(s[i]==']' && st.size()>0)
                st.pop();
            else 
                unbalanced++;
        }
        
        return (unbalanced+1)/2;
    }
};