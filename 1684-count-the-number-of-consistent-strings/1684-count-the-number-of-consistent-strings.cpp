class Solution 
{
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int ans = 0;
        map<char, int> mpp;

        for(int i=0; i<allowed.size(); i++)
        {
            mpp[allowed[i]]++;
        }
        
        for(int i=0 ; i<words.size(); i++)
        {
            string curr = words[i];
            bool status = true;
            
            for(int j=0; j<curr.size(); j++)
            {
                if(mpp.find(curr[j]) == mpp.end())
                {
                    status = false;
                    break;
                }
            }
            
            if(status)
                ans++;
        }
        
        return ans;
    }
};