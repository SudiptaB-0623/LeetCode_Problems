class Solution 
{
public:
    int countDistinctIntegers(vector<int>& nums) 
    {
        vector<int> sec;
        int count = 1;
        
        for(int i=0;i<nums.size();i++)
        {
            int cpy=nums[i];
            int rev=0;
            
            while(cpy!=0)
            {
                rev = (rev*10)+(cpy%10);
                cpy=cpy/10;
            }
            
            sec.push_back(rev);
        }
        nums.insert(nums.end(),sec.begin(),sec.end());
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
                count++;
        }
        
        return count;
    }
};