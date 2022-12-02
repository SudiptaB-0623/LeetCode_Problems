class Solution 
{
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        vector<int> ans{-1};
        
        if(arr.size()==1)
            return ans;
        
        int max = arr[arr.size()-1];
        
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i+1]>max)
                max = arr[i+1];
            
            ans.insert(ans.begin(),max);
        }
                
        return ans;
    }
};