class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int ans = 0;
        int right = arr[0];
        
        for(int i=0;i<arr.size();i++)
        {
            right = max(right, arr[i]);
            if(right == i)
                ans++;
        }        
        return ans;
    }
};