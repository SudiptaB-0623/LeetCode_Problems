class Solution 
{
public:
    int maxVowels(string s, int k) 
    {
        int ans = 0, count = 0;
        for(int i=0;i<s.size();i++)
        {  
            if(s.size()-i<=k)
            {
                if(i==0)
                {
                    for(int m=i;m<s.size(); m++)
                    {
                        if(s[m]=='a' || s[m]=='e' || s[m]=='i' || s[m]=='o' || s[m]=='u')
                            count++;
                    }
                    ans = count;
                    break;
                }
                if(s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u')
                    count -= 1;
                if(s[i+k-1]=='a' || s[i+k-1]=='e' || s[i+k-1]=='i' || s[i+k-1]=='o' || s[i+k-1]=='u')
                    count += 1;
                
                if(count>ans)
                    ans = count;
                break;
            }
            if(i==0)
            {
                for(int j=0, m=i;j<k;j++, m++)
                {
                    if(s[m]=='a' || s[m]=='e' || s[m]=='i' || s[m]=='o' || s[m]=='u')
                        count++;
                }
                ans = count;
                continue;
            }
            if(s[i-1]=='a' || s[i-1]=='e' || s[i-1]=='i' || s[i-1]=='o' || s[i-1]=='u')
                count -= 1;
            if(s[i+k-1]=='a' || s[i+k-1]=='e' || s[i+k-1]=='i' || s[i+k-1]=='o' || s[i+k-1]=='u')
                count += 1;
            
            if(count>ans)
                ans = count;
        }
        return ans;
    }
};