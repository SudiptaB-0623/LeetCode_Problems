// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        int l=1,r=n,m=0,i=0;
        
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(isBadVersion(m)==true)
            {
                i=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return i;
    }
};