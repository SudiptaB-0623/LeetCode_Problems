class Solution 
{
public:
    int partitionString(string s) 
    {
        int hp = 0, ans = 1;
        for(int i=0;i<s.size();i++)
        {
            if(hp&(1<<(s[i]-'a')))
            {
                hp=0;
                ans++;
            }
            hp^=(1<<(s[i]-'a'));
        }
        return ans;
    }
};