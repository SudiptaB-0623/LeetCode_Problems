class Solution 
{
public:
    int findClosestNumber(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        
        nums.push_back(0);
        sort(nums.begin(),nums.end());
        
        vector<int> :: iterator it;
        it = find(nums.begin(),nums.end(),0);
        int pos = it - nums.begin();
        
        if(pos==0)
            return nums[1];
        else
        {
            if(abs(nums[pos-1])<abs(nums[pos+1]))
                return nums[pos-1];
            else
                return nums[pos+1];
        }
    }
};