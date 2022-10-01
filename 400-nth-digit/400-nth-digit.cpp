class Solution 
{
public:
    int findNthDigit(int n) 
    {
        if(n<=9)
            return n;
        
        long long ans,dig=1,round=9,num=n;
        while(num>(round*dig))
        {
            num=num-(round*dig);
            round=round*10;
            dig++;
        }
        //cout<<dig<<" "<<num;
                
        int number=(num/dig)+(pow(10,dig-1)-1)+(num%dig?1:0);
        //cout<<endl<<number<<endl<<num%dig;
        
        if(num%dig==0)
            ans=number%10;
        else
        {
            ans=number/pow(10,(dig-(num%dig)));
            ans=ans%10;
        }
        
        return ans;
    }
};