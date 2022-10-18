class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int n = s.length(), m = t.length();
        vector<double> dyd(m+1, 0);
        dyd[0] = 1;
        for(int i = 1; i <= n; i++) 
        {
            for(int j = m; j > 0; j--) 
            {
                if(s[i-1] == t[j-1]) dyd[j] = dyd[j-1] + dyd[j];
            }
        }
        return dyd[m];    
    }
};