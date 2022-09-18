class Solution 
{
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int count=0,med=nums.size()/2;
        
        for(int i=0,j=nums.size()-1;(i<=j && nums.size()%2!=0) || (i<j && nums.size()%2==0) ;i++,j--)
        {
            count=count+abs(nums[med]-nums[i]);
            if(i != j)
                count=count+abs(nums[med]-nums[j]);
            
        }
        return count;
    }
};