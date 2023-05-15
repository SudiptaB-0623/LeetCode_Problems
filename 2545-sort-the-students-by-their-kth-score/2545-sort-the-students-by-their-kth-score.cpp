class Solution 
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) 
    {
        map<int, int, greater<int>> mpp;
        for(int i=0;i<score.size();i++)
        {
            mpp[score[i][k]] = i;
        }
        int i = 0;
        for(auto it : mpp)
        {
            int temp = score[i][k];
            swap(score[it.second],score[i]);
            mpp[temp] = it.second;
            i++;
        }
        return score;
    }
};