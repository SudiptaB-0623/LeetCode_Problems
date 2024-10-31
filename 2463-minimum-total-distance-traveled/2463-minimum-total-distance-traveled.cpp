class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> positions;
        for (auto& fact : factory) 
        {
            for (int i = 0; i < fact[1]; i++) 
            {
                positions.push_back(fact[0]);
            }
        }

        int robotCount = robot.size();
        int factoryCount = positions.size();
        vector<long long> next(factoryCount + 1, 0);
        vector<long long> current(factoryCount + 1, 0);

        for(int i=robotCount-1; i>=0; i--) 
        {
            if(i != robotCount-1) 
                next[factoryCount] = 1e12;
            current[factoryCount] = 1e12;

            for(int j=factoryCount-1; j>=0; j--) 
            {
                long long assign = abs(robot[i] - positions[j]) + next[j + 1];
                long long skip = current[j + 1];
                current[j] = min(assign, skip);
            }
            next = current;
        }
        return current[0];
    }
};