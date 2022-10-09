class Solution 
{
public:
    int largestInteger(int num) 
    {
        if(num<100)
            return num;
        
        vector<int> odd,even;
        int cpy = num;
        int ans=0,count = 0;
        
        while(num!=0)
        {
            count++;
            num = num/10;
        }
        
        num = cpy;
        
        while(num!=0)
        {
            if((num%10)%2 == 1)
               odd.push_back(num%10);
            else
                even.push_back(num%10);
            num=num/10;
        }
        
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        
        for(long long i=0,j=0,k=0,l=1;i<count;i++)
        {
            if((cpy%10)%2 == 1)
            {
                ans = (odd[j]*l) + ans;
                j++;
            }
            else
            {
                ans = (even[k] * l) +ans;
                k++;
            }
            cpy=cpy/10;
            l=l*10;
        }
                        
        return ans;
    }
};