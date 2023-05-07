class Solution 
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        int a = obstacles.size();
        
        vector<int> ans(a, 1), lis;
        
        for (int i = 0; i <a; ++i) 
        {
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (idx == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[idx] = obstacles[i];
            ans[i] = idx + 1;
        }
        return ans;
    }
};