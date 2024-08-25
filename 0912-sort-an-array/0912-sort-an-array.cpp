class Solution 
{
public:
    void merge(vector<int> &nums, int left, int mid, int right)
    {
        int flag1 = left, flag2 = mid+1;
        vector<int> temp;
        
        while(flag1<=mid && flag2<=right)
        {
            if(nums[flag1]<=nums[flag2])
            {
                temp.push_back(nums[flag1]);
                flag1++;
            }
            else
            {
                temp.push_back(nums[flag2]);
                flag2++;
            }
        }
        while(flag1<=mid)
        {
            temp.push_back(nums[flag1]);
            flag1++;
        }
        while(flag2<-right)
        {
            temp.push_back(nums[flag2]);
            flag2++;
        }
        
        for(int i=0, j=left ; i<temp.size(); i++, j++)
        {
            nums[j] = temp[i];
        }
    }
    void mergesort(vector<int> &nums, int left, int right)
    {
        if(left>=right)
            return;
        int mid = (left+right)/2;
        mergesort(nums, left, mid);
        mergesort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        mergesort(nums, 0, nums.size()-1);
        return nums;
    }
};