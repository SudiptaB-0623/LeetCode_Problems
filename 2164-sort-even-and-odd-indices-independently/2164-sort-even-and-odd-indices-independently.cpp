class Solution 
{
public:
    vector<int> sortEvenOdd(vector<int>& nums) 
    {
        vector<int> odd;
        vector<int> even;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                even.push_back(nums[i]);
            }
            else
                odd.push_back(nums[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        
        for(int i=0,j=0,k=odd.size()-1;i<nums.size();i++)
        {
            if(i%2==0)
            {
                nums[i]=even[j];
                j++;
            }
            else
            {
                nums[i]=odd[k];
                    k--;
            }
        }
        return nums;
    }
};