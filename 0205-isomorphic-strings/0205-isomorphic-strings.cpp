class Solution 
{
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char, char> mpp;
        for(int i=0; i<s.size(); i++)
        {
            if(mpp.find(s[i]) != mpp.end())
            {
                if(mpp[s[i]] != t[i])
                    return false;
            }
            else
            {
                mpp[s[i]] = t[i];
            }
        }
        mpp.clear();
        for(int i=0; i<s.size(); i++)
        {
            if(mpp.find(t[i]) != mpp.end())
            {
                if(mpp[t[i]] != s[i])
                    return false;
            }
            else
            {
                mpp[t[i]] = s[i];
            }
        }
        
        return true;
    }
};