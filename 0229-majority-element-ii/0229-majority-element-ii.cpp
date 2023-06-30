class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1 == 0 && nums[i]!=ele2)
            {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i]!=ele1)
            {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == ele1)
                cnt1++;
            else if(nums[i] == ele2)
                cnt2++;
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == ele1)
                cnt1++;
            if(cnt1 >= (nums.size()/3)+1)
            {
                ans.push_back(ele1);
                break;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == ele2)
                cnt2++;            
            
            if(cnt2 >= (nums.size()/3)+1)
            {
                ans.push_back(ele2);
                break;
            }
        }
        return ans;
    }
};