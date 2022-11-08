class Solution 
{
public:
    string makeGood(string s) 
    {
        if(s.size()==1)
            return s;
        vector<char> ch;
        
        for(int i=0;i<s.size();i++)
        {
            ch.push_back(s[i]);
        }
        
        for(int i=0;i<=ch.size()-2;i++)
        {
            if(tolower(ch[i]) == tolower(ch[i+1]))
            {
                if((islower(ch[i]) && isupper(ch[i+1])) || (isupper(ch[i]) && islower(ch[i+1])))
                {                
                    vector<char> :: iterator it;
                    it = ch.begin()+i;
                    ch.erase(it);
                    ch.erase(it);
                    if(ch.size()==0 || ch.size()==1)
                        break;
                    i=-1;
                }
            }
        }       
                
        string ans = {};
        
        if(ch.size()==0)
            return ans;        
        else
        {
            for(int i=0;i<ch.size();i++)
            {
                ans = ans+ch[i];              
            }
        }
        return ans;
    }
};