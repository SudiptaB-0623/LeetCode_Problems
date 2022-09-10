class Solution 
{
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        vector<int>::iterator it;
        
        for(int i=0;i<nums.size();i++)
        {
            it=find(nums.begin(),nums.end(),original);
            if(it!=nums.end())
                original=original*2;
            else
                break;
        }
        
        return original;
    }
};