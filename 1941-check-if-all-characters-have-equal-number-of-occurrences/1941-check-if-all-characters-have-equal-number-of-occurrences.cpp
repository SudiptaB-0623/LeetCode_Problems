class Solution 
{
public:
    bool areOccurrencesEqual(string s) 
    {
        int a=1,b=-1;
        vector<char> str;
        for(int i=0;i<s.size();i++)
        {
            str.push_back(s[i]);
        }
        sort(str.begin(),str.end());
        for(int i=1;i<str.size();i++)
        {
            if(str[i]==str[i-1])
            {
                a++;
            }
            else
            {
                if(b==-1  || b==a)
                {
                    b=a;
                    a=1;
                }
                else if(b!=a)
                    return false;
            }
        }
        if(a==b  || b==-1)
            return true;
        else
            return false;
    }
};