class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        int n = s.size();
        int m = goal.size();
        if(n!=m)
            return false;
        
        for(int i=0; i<n ; i++)
        {
            if(s[i] == goal[0])
            {
                int j=0;
                for(int k=i ; j<m ; j++, k++)
                {
                    if(goal[j] != s[k%n])
                        break;
                }
                if(j == m)
                    return true;
            }
        }
        
        return false;
    }
};