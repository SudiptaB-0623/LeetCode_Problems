class Solution 
{
public:
    int getMinDistance(vector<int>& nums, int target, int start) 
    {
        int ind=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                
                int t=abs(i-start);
                if(ind==-1)
                    ind=t;
                else if(t<ind)
                    ind=t;
            }
        }
        return ind;
    }
};