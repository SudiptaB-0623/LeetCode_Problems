class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans ;
        vector<int> unav = {-1,-1};
        
        if(nums.size()==0)
            return unav;
        if(nums.size()==1)
        {
            if(nums[0]==target)
            {
                ans.push_back(0);
                ans.push_back(0);
                return ans;
            }
            else
                return unav;
        }
        
        int left = 0, right = nums.size()-1;
        
        while(left<=right)
        {
            int mid = left + ((right-left)/2);
                   
            if(nums[mid]==target)
            {
                left = mid;
                right = mid;
                while(left>0)
                {
                    
                    if(nums[left]==nums[left-1]) 
                        left--;
                    else
                        break;
                }
                while(right<nums.size()-1)
                {
                    
                    if(nums[right]==nums[right+1]) 
                        right++;
                    else
                        break;
                }
                
                ans.push_back(left);
                ans.push_back(right);
                
                return ans;
            }
            
            else if(nums[mid]<target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid -1;
            }
        }
        return unav;
    }
};