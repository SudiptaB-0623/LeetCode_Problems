class Solution 
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        sort(logs.begin(),logs.end());
        
        vector<int> ans;
        map<int,int> mpp;
        
        for(int i=0;i<logs.size();i++)
        {            
            int count = 1;
            for(int j=i+1;j<logs.size();j++,i++)
            {
                if(logs[j][0]!=logs[i][0])
                {                    
                    break;
                }
                else
                {
                    if(logs[j][1]==logs[j-1][1])
                        continue;
                    else
                        count++;
                }
            }
            auto it = mpp.find(count);
            if(it!=mpp.end())
            {
                (it->second)++;                
            }
            else
            {
                mpp[count]=1;
            }
        }
        
       for(int i=1;i<=k;i++)
       {
           auto it = mpp.find(i);
           if(it!=mpp.end())
            {
                ans.push_back(it->second);
            }
            else
            {
                ans.push_back(0);
            }
       }                      
        
        return ans;
    }
};