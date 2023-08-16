class Solution 
{
public:
    int romanToInt(string s) 
    {
        int integer = 0;
        int n = s.size();
        
        map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        
        for(int i=0 ; i<n ; i++)
        {
            if(i+1 == n || mpp[s[i]] >= mpp[s[i+1]])
                integer += mpp[s[i]];
            else
                integer -= mpp[s[i]];
        }
        
        return integer;
    }
};