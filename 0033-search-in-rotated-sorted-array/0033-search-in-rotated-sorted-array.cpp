class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        vector<int> :: iterator it;
        
        it=find(nums.begin(),nums.end(),target);
        
        if(it==nums.end())
            return -1;
        else
            return (it-nums.begin());
    }
};