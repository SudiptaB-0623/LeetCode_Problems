class Solution 
{
public:
    int minLength(string s) 
    {
        int n = s.size();
        int ptr = 0;
        
        while(ptr<s.size()-1)
        {            
            if((s[ptr]=='A' && s[ptr+1]=='B') || (s[ptr]=='C' && s[ptr+1]=='D'))
            {
                s.erase(ptr, 2);
                ptr = 0;
            }
            else
            {
                ptr++;
            }
            
            if(s.size()<=0)
                break;
        }
        
        return s.size();
    }
};