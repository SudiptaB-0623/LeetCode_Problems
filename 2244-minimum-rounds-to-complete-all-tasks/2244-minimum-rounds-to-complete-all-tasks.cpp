class Solution 
{
public:
    int minimumRounds(vector<int>& tasks) 
    {
        sort(tasks.begin(),tasks.end());
        int ans = 0;
        
        map<int,int> mpp;
        
        mpp[tasks[0]]=1;
        
        for(int i=1;i<tasks.size();i++)
        {
            if(tasks[i]==tasks[i-1])
                mpp[tasks[i]]++;
            else
            {
                mpp[tasks[i]]=1;
            }
        }
        
        map<int,int> :: iterator it;
        
        for(it=mpp.begin();it!=mpp.end();it++)
        {
            if(it->second==1)
                return -1;
            else
            {
                int freq = it->second;
                while(freq>0)
                {
                    if(freq%3==0)
                    {
                        ans += freq/3;
                        freq=0;
                    }
                    else
                    {
                        ans++;
                        freq-=2;
                    }
                }
            }
        }
        
        return ans;
    }
};