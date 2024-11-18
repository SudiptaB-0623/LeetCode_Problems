class Solution 
{
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();
        vector<int> ans(n, 0);
        
        if(k==0)
            return ans;
        
        int i = 1;
        if(k<0)
            i = n + k;
        int sum = 0;
        int count = abs(k);
        
        while(count>0)
        {
            sum += code[i%n];
            i++;
            count--;
        }
        
        ans[0] = sum;
        int left = 1;
        if(k<0)
            left = n + k;
        int right = (left + abs(k)) % n;
        
        for(int j = 1; j < n; j++)
        {
            sum -= code[left];
            sum += code[right];
            
            left = (left+1)%n;
            right = (right+1)%n;
            
            ans[j] = sum;
        }
        
        return ans;
    }
};