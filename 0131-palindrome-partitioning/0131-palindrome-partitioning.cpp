class Solution 
{
public:
    bool isPalin(int start, int end, string s)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int ind, vector<string> &ds, vector<vector<string>> &ans, string s)
    {
        if(ind == s.size())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind; i<s.size(); i++)
        {
            if(isPalin(ind, i, s))
            {
                string temp = s.substr(ind, i-ind+1);
                ds.push_back(temp);
                solve(i+1, ds, ans, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> ds;
        
        solve(0, ds, ans, s);
        
        return ans;
    }
};