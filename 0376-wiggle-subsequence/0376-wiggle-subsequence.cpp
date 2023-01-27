class Solution 
{
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
    
    int n=nums.size();
    int i1=0,i2=0;
    for(int i=1;i<n;i++)
    {
       if(nums[i]>nums[i-1])
       {
           i1=i2+1;
       }
        else if(nums[i]<nums[i-1])
        {
            i2=i1+1;
        }
    }
    if(i1>i2)
        return i1+1;
    else
        return i2+1;
}
};