class Solution 
{
public:
    void rotateArray(vector<int>& nums, int left, int right)
    {
        while(left<right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        k = k%nums.size();
        rotateArray(nums, 0, nums.size()-k-1);
        rotateArray(nums, nums.size()-k, nums.size()-1);
        rotateArray(nums, 0, nums.size()-1);
    }
};