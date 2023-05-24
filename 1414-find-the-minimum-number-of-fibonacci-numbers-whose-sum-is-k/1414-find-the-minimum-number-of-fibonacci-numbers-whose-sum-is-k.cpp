class Solution 
{
public:
    int findMinFibonacciNumbers(int k) 
    {
        if(k == 1 || k == 2) 
            return 1;

        vector<int> vec {1,1};
        int ans = 0, num = 2; 
        
        while(num <= k)
        {
            vec.push_back(num);

            int temp1 = vec.back();
            int temp2 = vec[vec.size()-2];

            num = temp1 + temp2;
        }
        
        for(int i = vec.size()-1; k > 0;)
        {
            while(i >= 0 && vec[i] > k)
            {
                i--;
            }

            k = k - vec[i];
            ans++;
        }

        return ans;
    }
};