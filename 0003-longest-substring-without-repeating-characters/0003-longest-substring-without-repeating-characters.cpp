class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char, int> alpha;
        int left = 0, right = 0;
        int n = s.size();
        int ans = 0;
        
        while(right<n)
        {
            alpha[s[right]]++;
            while(alpha[s[right]] > 1)
            {
                alpha[s[left]]--;
                left++;
            }
            
            ans = max(ans, right-left+1);
            right++;
        }
        
        return ans;
    }
};