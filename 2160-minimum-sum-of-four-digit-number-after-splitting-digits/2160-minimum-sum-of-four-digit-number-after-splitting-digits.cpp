class Solution 
{
public:
    int minimumSum(int num) 
    {
        vector<int> nums;
        int n1=0,n2=0;
        for(int i=0;i<4;i++)
        {
            int t=num%10;
            num=num/10;
            nums.push_back(t);
        }
        sort(nums.begin(),nums.end());
        n1=(nums[0]*10 + nums[2]);
        n2=(nums[1]*10 + nums[3]);
        
        return (n1+n2);
    }
};