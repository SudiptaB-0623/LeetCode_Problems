class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int count=0;
        int c=x^y;
        ;
        for(int i=0;c>0;i++)
        {
            if(c%2==1)
                count++;
            c=c/2;
        }
        return count;
    }
};