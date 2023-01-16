class Solution 
{
public:
    string truncateSentence(string s, int k) 
    {
        s.append(" ");
        
        int i=0;
        for(int j=0;j<k && i<s.size();i++)
        {
            if(s[i]==' ')
                j++;
        }
        
        s.erase(s.begin()+i-1,s.end());
        
        return s;
    }
};