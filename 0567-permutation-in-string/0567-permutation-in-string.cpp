class Solution 
{
public:
    bool match(map<char, int> mpp1, map<char, int> mpp2)
    {
        for(auto ele : mpp1)
        {
            if(mpp2.find(ele.first) == mpp2.end())
                return false;
            if(mpp2[ele.first] != ele.second)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        int n = s1.size();
        int m = s2.size();
        if(n>m)
            return false;
        
        map<char, int> mpp1, mpp2;       
        
        for(int i=0; i<n; i++)
        {
            mpp1[s1[i]]++;
            mpp2[s2[i]]++;
        }
        
        int p1 = 0;
        int p2 = n-1;
        
        while(p2<m)
        {
            if(match(mpp1, mpp2))
                return true;
            
            p2++;
            if(p2<m)
                mpp2[s2[p2]]++;
            
            mpp2[s2[p1]]--;
            if(mpp2[s2[p1]]<=0)
                mpp2.erase(s2[p1]);
            
            p1++;
        }
        
        return false;
    }
};