class Solution 
{
public:
    int countPrimes(int n) 
    {
        int arr[n+1];
        fill(arr,arr+n+1,1);
        
        for(int i=2;i*i<n;i++)
        {
            if(arr[i]!=0)
            {
                for(int j=i*i;j<n;j=j+i)
                {
                    arr[j]=0;
                }
            }
        }
        
        int count = 0;
        
        for(int i=2;i<n;i++)
        {
            if(arr[i]!=0)
                count++;
        }
        
        return count;
    }
};