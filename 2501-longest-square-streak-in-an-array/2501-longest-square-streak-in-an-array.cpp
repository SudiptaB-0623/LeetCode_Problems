class Solution 
{
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        int longestStreak = 0;
        unordered_set<int> values(nums.begin(), nums.end());
        
        for(int currentNum : nums)
        {
            int streak = 0;
            long long num = currentNum;
            while(values.find(num) != values.end())
            {
                streak++;
                if(num*num > 1e5)
                    break;
                num = num*num;
            }
            
            longestStreak = max(longestStreak, streak);
        }
        
        return (longestStreak<2)?-1:longestStreak;
    }
};