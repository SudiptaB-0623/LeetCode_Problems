class Solution 
{
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) 
    {
        vector<int> vec1,vec2,vec3,vec4;
        long long int res = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]&1)
            {
                vec1.push_back(nums[i]);
            }
            else
            {
                vec3.push_back(nums[i]);
            }
            if(target[i]&1)
            {
                vec2.push_back(target[i]);
            }
            else
            {
                vec4.push_back(target[i]);
            }
        }
        
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        sort(vec3.begin(),vec3.end());
        sort(vec4.begin(),vec4.end());
        
        for(int i = 0; i < vec3.size(); i++)
        {
            res += abs(vec3[i]-vec4[i]);
        }
        for(int i = 0; i < vec1.size(); i++)
        {
            res += abs(vec1[i]-vec2[i]);
        }
        return (res>>2);
    }
};