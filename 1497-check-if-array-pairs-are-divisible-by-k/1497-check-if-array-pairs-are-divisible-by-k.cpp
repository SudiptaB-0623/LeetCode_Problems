class Solution 
{
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        map<int, int> remCount;
        
        for(int i=0; i<arr.size(); i++)
            remCount[((arr[i]%k)+k)%k]++;
        
        cout<<-1%-5;
        for(int i=0; i<arr.size(); i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            
            if(rem == 0)
            {
                if(remCount[rem]%2 == 1)
                    return false;
            }
            else if(remCount[rem] != remCount[k-rem])
                return false;
        }
        
        return true;
    }
};