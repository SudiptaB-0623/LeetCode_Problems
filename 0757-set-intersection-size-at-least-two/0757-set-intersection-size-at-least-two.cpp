class Solution 
{
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end(), [](vector<int>& first, vector<int>& second) 
             { return first[1] < second[1] || (first[1] == second[1] && first[0] > second[0]); });
        
        int n = intervals.size();
        int result = 0, part1 = -1, part2 = -1;
        
        for (int i = 0; i < n; i++) 
        {
            if (intervals[i][0] <= part1) 
            {
                continue;
            }
            if (intervals[i][0] > part2) 
            {
                result = result + 2;
                part2 = intervals[i][1];
                part1 = part2-1;
            }
            else 
            {
                result = result + 1;
                part1 = part2;
                part2 = intervals[i][1];
            }
        }
        return result;
    }
};