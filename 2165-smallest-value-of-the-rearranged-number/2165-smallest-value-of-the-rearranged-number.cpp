class Solution 
{
public:
    long long smallestNumber(long long num) 
    {
        if(num == 0)
            return 0;
        
        vector<int> digits;
        long long cpy = num;
        long long ans=0;
        
        while(num!=0)
        {
            digits.push_back(num%10);
            num=num/10;
        }
        
        sort(digits.begin(),digits.end());
                
        if(digits[0]==0)
        {
            int i=1;
            while(digits[i]==0)
            {
                i++;
            }
            ans = ans + digits[i];
            digits.erase(digits.begin()+i);
        }
        
        for(int i=0;i<digits.size();i++)
        {
            ans=(ans*10)+digits[i];
        }
        return ans;
    }
};