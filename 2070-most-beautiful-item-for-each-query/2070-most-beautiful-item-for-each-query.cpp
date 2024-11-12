class Solution 
{
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) 
    {
        int n = items.size();
        int m = queries.size();
        vector<int> ans(m);
        
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});

        vector<vector<int>> queriesWithIndices(m, vector<int>(2));

        for(int i=0; i<m; i++) 
        {
            queriesWithIndices[i][0] = queries[i];
            queriesWithIndices[i][1] = i;
        }

        sort(queriesWithIndices.begin(), queriesWithIndices.end(),
             [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});

        int itemIndex = 0;
        int maxBeauty = 0;

        for(int i=0; i<m; i++) 
        {
            int query = queriesWithIndices[i][0];
            int originalIndex = queriesWithIndices[i][1];

            while(itemIndex<n && items[itemIndex][0]<=query) 
            {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            ans[originalIndex] = maxBeauty;
        }
        
        return ans;
    }
};