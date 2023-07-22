class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;
        
        map<int, int> mpp;
        int n = s.size();
        int m = t.size();
        
        for(int i=0 ; i<n ; i++)
        {
            mpp[s[i]]++;
        }
        for(int i=0; i<m; i++)
        {
            mpp[t[i]]--;
        }
        
        for(auto it : mpp)
        {
            if(it.second != 0)
                return false;
        }
        return true;
    }
};