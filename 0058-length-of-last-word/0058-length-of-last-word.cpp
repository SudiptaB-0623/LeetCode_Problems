class Solution 
{
public:
    int lengthOfLastWord(string s) 
    {    
        if(s.size()==1)
            return 1;
        
        int i=s.size()-1,count = 0;
        
        for(;s[i]==' ';i--);
        
        for(; s[i]!=' ' && (i>=0);i--)
        {            
            count++;
            if(i-1<0)
                break;
        }
        
        return count;
    }
};