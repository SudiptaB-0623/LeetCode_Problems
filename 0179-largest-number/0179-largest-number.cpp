class Solution 
{
public:
    string largestNumber(vector<int>& nums) 
    {
        string ans = "";
        vector<string> strings;
        
        for(int i=0; i<nums.size(); i++)
            strings.push_back(to_string(nums[i]));
        
        sort(strings.begin(), strings.end(), [](string &a, string &b){return a+b > b+a;});
        
        if(strings[0] == "0")
            return "0";
        
        for(int i=0; i<strings.size(); i++)
            ans += strings[i];
        
        return ans;
    }
};