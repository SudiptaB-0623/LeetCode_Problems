class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> ans;
        vector<int> a, b;
        map<int, int> mpp;
        for(int i=0;i<nums2.size();i++)
            mpp[nums2[i]]++;
        for(int i=0;i<nums1.size();i++)
        {
            mpp[nums1[i]]++;
            if(mpp[nums1[i]] == 1)
                a.push_back(nums1[i]);
        }
        ans.push_back(a);
        map<int, int> mpp2;
        for(int i=0;i<nums1.size();i++)
            mpp2[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
        {
            mpp2[nums2[i]]++;
            if(mpp2[nums2[i]] == 1)
                b.push_back(nums2[i]);
        }
        ans.push_back(b);
        return ans;
    }
};