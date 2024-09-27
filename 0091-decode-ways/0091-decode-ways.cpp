class Solution 
{
public:
    int recur(int ind, string s, vector<int> &dp)
    {
        if(ind == s.size())
            return 1;
        if(s[ind] == '0')
            return dp[ind] = 0;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        int one = 0, two =0;
                
        one = recur(ind+1, s, dp);
        
        if(ind+2<=s.size())
        {
            string temp = s.substr(ind, 2);
            if(stoi(temp) <= 26)
                two = recur(ind+2, s, dp);
        }
        
        return dp[ind] = one+two;
    }
    int numDecodings(string s) 
    {
        vector<int> dp(s.size()+1, -1);
        if(s[0] == '0')
            return 0;
        
        return recur(0, s, dp);
    }
};