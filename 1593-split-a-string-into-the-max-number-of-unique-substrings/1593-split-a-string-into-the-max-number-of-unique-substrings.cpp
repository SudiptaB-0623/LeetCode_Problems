class Solution 
{
public:
    int findSub(int ind, string s, unordered_map<string, int> &mpp)
    {
        if(ind == s.size())
            return 0;
        
        int maxCount = 0;
        
        for(int i = ind+1; i<=s.size(); i++)
        {
            string temp = s.substr(ind, i-ind);
            
            if(mpp.find(temp) == mpp.end())
            {
                mpp[temp] = 1;
                maxCount = max(maxCount, 1+findSub(i, s, mpp));
                mpp.erase(temp);
            }
        }
        
        return maxCount;
    }
    int maxUniqueSplit(string s) 
    {
        unordered_map<string, int> mpp;
        return findSub(0, s, mpp);
    }
};