class Solution 
{
public:
    int myAtoi(string s) 
    {
        long long int ans=0;
        char str;
        int tc=0,tc2=0;
        for(int i=0;i<s.size();i++)
        {
            if((tc2>0)&&((s[i]<48)||(s[i]>57)))
                break;
            if(s[i]==' ' && tc==0)
            {
                continue;
            }
            if(s[i]==' ' && tc>0)
            {
                break;
            }
            if((s[i]=='-') || (s[i]=='+'))
            {
                tc++;
                str=s[i];
                if((s[i+1]<48)||(s[i+1]>57))
                    return 0;
            }
            //if((str=='+' || str=='-')&&((s[i]<48)||(s[i]>57)))
                //return 0;
            if((s[i]>=48) && (s[i]<=57))
            {
                tc++;
                if(((ans*10)+(s[i]-48) > INT_MAX) && (str!='-'))
                        return INT_MAX;
                if(((ans*10)+(s[i]-48))*(-1) < INT_MIN)
                    return INT_MIN;
                ans=(ans*10)+(s[i]-48);
                tc2++;
                continue;
            }
            
            if(tc==0)
                return 0;
            if(tc2>0)
                break;
        }
        if(str=='-')
        {
            ans=ans*-1;
        }
        return ans;
    }
};