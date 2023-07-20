class Solution 
{
public:
    string reverseWords(string s) 
    {
        string ans = "";
        string word = "";
        int n = s.size();
        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == ' ')
                continue;
            
            word = "";
            while(i<n)
            {
                word = word+s[i];
                i++;
                if(i!=n && s[i] == ' ')
                    break;
            }
            
            if(ans.size()==0)
                ans = word;
            else
                ans = word + ' ' + ans;
        }
        
        return ans;
    }
};