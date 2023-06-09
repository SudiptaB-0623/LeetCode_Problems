class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = 1, high = nums.size();
        int curr;
        
        while(low<high)
        {
            int mid = (low+high)/2;
            int count =0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<=mid)
                    count++;
            }
            if(count>mid)
            {
                curr = mid;
                high = mid;
            }
            else
                low=mid+1;
        }
        return curr;
    }
};