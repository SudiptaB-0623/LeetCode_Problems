class Solution 
{
public:
    int countTriples(int n) 
    {
        int count=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                //cout<<j<<"   "<<n<<endl;
                int sq=pow(i,2)+pow(j,2);
                int sum=sqrt(sq);
                
                if(sum*sum == sq && sum<=n)
                {
                    count=count+2;
                    //cout<<i<<"  "<<j<<"  "<<sq<<"   "<<sum<<endl;
                }
            }
        }
        return count;
    }
};