class Solution 
{
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        int n = nums.size();
        priority_queue<int> pq;
        
        for(int i=0; i<n; i++)
            pq.push(nums[i]);
        
        long long ans = 0;
        for(int i=0; i<k; i++)
        {
            int num = pq.top();
            pq.pop();
            //cout<<num<<" "<<ceil((double)num/3)<<endl;
            ans += num;
            pq.push(ceil((double)num/3));
        }
        
        return ans;
    }
};