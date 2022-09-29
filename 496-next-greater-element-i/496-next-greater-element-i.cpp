class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        vector<int> :: iterator it;
        
        for(int i=0;i<nums1.size();i++)
        {
            it=find(nums2.begin(),nums2.end(),nums1[i]);
            int pos=it-nums2.begin();
            int flag=0;
            
            for(int j=pos+1;j<nums2.size();j++)
            {
                if(nums1[i]<nums2[j])
                {
                    ans.push_back(nums2[j]);
                    flag++;
                    break;
                }
            }
            
            if(flag==0)
                ans.push_back(-1);
        }
        
        return ans;
    }
};