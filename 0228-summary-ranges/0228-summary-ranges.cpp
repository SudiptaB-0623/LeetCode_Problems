class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> ans;
        
        if(nums.size()==0)
            return ans;
        
        long long min = nums[0], max = nums[0];
        
        for(long long i=1, j=nums[0]+1;i<nums.size();i++)
        {
            if(nums[i]==j)
            {
                max=nums[i];
                j++;
                continue;
            }
            else
            {
                string s;
                if(max!=min)
                {
                    s.append(to_string(min));
                    s.append("->");
                    s.append(to_string(max));
                }
                else
                    s = to_string(min);
                ans.push_back(s);
                
                min = nums[i];
                max = nums[i];
                if(nums[i]==INT_MAX)
                    break;
                j = nums[i]+1;
            }
        }
        
        string s;
        if(max!=min)
        {
            s.append(to_string(min));
            s.append("->");
            s.append(to_string(max));
        }
        else
            s = to_string(min);
        
        ans.push_back(s);
        
        return ans;
    }
};