class Solution 
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) 
    {
        vector<bool> ans;
        
        for(int i=0;i<l.size();i++)
        {           
            
            vector<int> temp;
            temp.assign(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
                        
            int diff = temp[1]-temp[0], flag=0;
            
            for(int j=2;j<temp.size();j++)
            {
                if(temp[j]-temp[j-1]!=diff)
                {
                    ans.push_back(0);
                    flag++;
                    break;
                }                
            }
            if(flag==0)
                ans.push_back(1);
        }
        return ans;
    }
};