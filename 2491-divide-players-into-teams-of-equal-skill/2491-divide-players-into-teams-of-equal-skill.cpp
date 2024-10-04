class Solution 
{
public:
    long long dividePlayers(vector<int>& skill) 
    {
        int n = skill.size();
        
        if(n == 2)
            return skill[0]*skill[1];
        
        long long sum = 0;
        for(auto num : skill)
            sum += num;
        
        int teams = n/2;
        long long target = sum/teams;
        
        if(sum%teams != 0)
            return -1;
        
        unordered_map<int, int> mpp;
        long long ans = 0;
        
        for(auto num : skill)
        {
            if(num >= target)
                return -1;
            
            if(mpp.find(target-num) == mpp.end())
                mpp[num]++;
            else
            {
                ans += (num * (target-num));
                mpp[target-num]--;
                
                if(mpp[target-num] == 0)
                    mpp.erase(target-num);
            }
        }
        
        return mpp.size() == 0 ? ans : -1;
    }
};