class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        
        sort(nums1.begin(),nums1.end());
        vector<int> :: iterator it;
        
        for(int i=0;i<nums1.size();i++)
        {
            it = find(nums2.begin(),nums2.end(),nums1[i]);
            if(it!=nums2.end())
            {
                ans.push_back(nums1[i]);
                nums2[it-nums2.begin()]=-1;
            }
        }
        
        return ans;
    }
};