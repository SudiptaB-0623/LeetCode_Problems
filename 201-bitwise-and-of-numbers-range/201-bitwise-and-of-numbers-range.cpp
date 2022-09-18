class Solution 
{
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        if(left==right)
        {
            return left;
        }
        int left1=left,right1=right;
        int i=0,j=0;
        
        while(left1>0)
        {
            i++;
            left1=left1/2;
        }
        while(right1>0)
        {
            j++;       
            right1=right1/2;
        }
        
        if(i!=j)
            return 0;
        else
        {
            int ans=0;
            ans=ans+pow(2,(i-1));
            ans=ans+rangeBitwiseAnd((left-pow(2,(i-1))),(right-pow(2,(i-1))));
            return ans;
        }
        return 0;
    }
};