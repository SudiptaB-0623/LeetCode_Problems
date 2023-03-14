class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        unordered_map<char,int> mpp;
        int count = 0;
        
        for(auto i : tasks)
        {
            mpp[i]++;
            count = max(count, mpp[i]);
        }
        
        int ans = (count-1)*(n+1);
        for(auto e : mpp) 
        {
            if(e.second == count) 
                ans++;
        }
        
        return max((int)tasks.size(), ans);
    }
};