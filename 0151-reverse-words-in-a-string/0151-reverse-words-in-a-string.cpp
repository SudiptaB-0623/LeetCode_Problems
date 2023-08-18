class Solution 
{
public:
    string reverseWords(string s) 
    {
        s = s+' ';
        string ans = "";
        int n = s.size();
        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == ' ')
                continue;
            
            string temp = "";
            while(s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            i--;
            
            if(ans.size() == 0)
                ans = temp;
            else
                ans = temp + ' ' + ans;
        }
        
        return ans;
    }
};