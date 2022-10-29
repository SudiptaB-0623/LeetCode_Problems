class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left<=right)
        {
            int mid = left + ((right-left)/2);
            
            if(nums[mid]==target)
                return true;
            else if(nums[mid]>target)
                right = mid -1;
            else
                left = mid + 1;
        }
        return false;
    }
};