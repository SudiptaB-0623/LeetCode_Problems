class Solution 
{
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int ans = 0;
        
        for(int i=1;i<=arr.size();i=i+2)
        {
            for(int j=0;j+i<=arr.size();j++)
            {
                int sum = 0;
                for(int k=i,l=j;k>0;k--,l++)
                {
                    //cout<<arr[l];
                    sum = sum+arr[l];
                }
                //cout<<endl;
                ans = ans+sum;
            }
        }
        return ans;
    }
};