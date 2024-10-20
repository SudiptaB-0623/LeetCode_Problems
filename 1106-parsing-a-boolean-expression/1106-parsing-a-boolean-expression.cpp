class Solution 
{
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> st;
        for (char curr : expression) 
        {
            if (curr == ',' || curr == '(')
                continue; 
            
            if (curr == 't' || curr == 'f' || curr == '!' || curr == '&' || curr == '|') 
                st.push(curr);
            else if (curr == ')') 
            {
                bool hasTrue = false;
                bool hasFalse = false;
                
                while (st.top() != '!' && st.top() != '&' && st.top() != '|') 
                {
                    char upperVal = st.top();
                    st.pop();
                    if (upperVal == 't') 
                        hasTrue = true;
                    if (upperVal == 'f') 
                        hasFalse = true;
                }
                
                char temp = st.top();
                st.pop();
                if (temp == '!') 
                    st.push(hasTrue ? 'f' : 't');
                else if (temp == '&')
                    st.push(hasFalse ? 'f' : 't');
                else
                    st.push(hasTrue ? 't' : 'f');
            }
        }
        
        return st.top() == 't';
    }
};