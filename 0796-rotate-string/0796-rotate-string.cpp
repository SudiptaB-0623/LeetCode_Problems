class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size())
            return false;
        
        int n = s.size();
        int m = goal.size();
        
        for(int i=0 ; i<n*2 ; i++)
        {
            int j=0;
            int k=i;
            for(; j<m ; j++, k++)
            {
                if(s[k%n] != goal[j])
                    break;
            }
            if(j==m)
                return true;
        }
        
        return false;
    }
};