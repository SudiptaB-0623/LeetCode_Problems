class Solution 
{
public:
    void recur(int ind, string s, vector<string> &ans)
    {
        if(ind == s.size())
        {
            ans.push_back(s);
            return;
        }
        
        for(int i=ind; i<s.size(); i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                s[i] = tolower(s[i]);
                recur(i+1, s, ans);
                s[i] = toupper(s[i]);
                recur(i+1, s, ans);
                break;
            }
            else if(i == s.size()-1)
                recur(i+1, s, ans);
        }
    }
    vector<string> letterCasePermutation(string s) 
    {
        vector<string> ans;
        
        recur(0, s, ans);
        
        return ans;
    }
};