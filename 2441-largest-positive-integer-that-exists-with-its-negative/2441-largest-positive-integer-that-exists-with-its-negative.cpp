class Solution 
{
public:
    int findMaxK(vector<int>& nums) 
    {
        vector<int> vec;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size() && nums[i]<0;i++)
        {
            vector<int> :: iterator it;
            it = find(nums.begin(),nums.end(),abs(nums[i]));
            if(it!=nums.end())
                vec.push_back(abs(nums[i]));
        }
        if(vec.size()==0)
            return -1;
        
        sort(vec.begin(),vec.end());
        
        return vec[vec.size()-1];        
    }
};