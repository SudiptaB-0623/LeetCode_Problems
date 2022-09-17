class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res;
        vector<int> :: iterator it;
        sort(nums1.begin(),nums1.end());
        
        it=find(nums2.begin(),nums2.end(),nums1[0]);
        if(it!=nums2.end())
            res.push_back(nums1[0]);
        
        for(int i=1;i<nums1.size();i++)
        {
            if(nums1[i]!=nums1[i-1])
            {
                it=find(nums2.begin(),nums2.end(),nums1[i]);
                if(it!=nums2.end())
                    res.push_back(nums1[i]);
            }
        }
        return res;
    }
};