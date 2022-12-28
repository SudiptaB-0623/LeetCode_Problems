class Solution 
{
    public:
        int romanToInt(string s) 
        {
            map<char,int> mpp;
            mpp['I']=1;
            mpp['V']=5;
            mpp['X']=10;
            mpp['L']=50;
            mpp['C']=100;
            mpp['D']=500;
            mpp['M']=1000;
            
            map<char,int> :: iterator it;
            
            int sum=0;
            
            for(int i=s.size()-1;i>=0;i--)
            {
                int a = 0;
                if((s[i]=='V')||(s[i])=='X')
                {
                    it = mpp.find(s[i]);
                    a = it->second;
                    
                    if((i-1>=0)&&(s[i-1]=='I'))
                    {
                        a = a-1;
                        i--;
                    }   
                    sum += a;
                    continue;
                }
                if((s[i]=='L')||(s[i])=='C')
                {
                    auto it = mpp.find(s[i]);
                    a = it->second;
                    
                    if((i-1>=0)&&(s[i-1]=='X'))
                    {
                        a = a-10;
                        i--;
                    }     
                    sum += a;
                    continue;
                }
                if((s[i]=='D')||(s[i])=='M')
                {
                    auto it = mpp.find(s[i]);
                    a = it->second;
                    
                    if((i-1>=0)&&(s[i-1]=='C'))
                    {
                        a = a-100;
                        i--;
                    }
                    sum += a;
                    continue;
                }
                if(s[i]=='I')
                {
                    a=1;
                    sum += a;
                    continue;
                }
                
                
            }
            
            return sum;
        }
};