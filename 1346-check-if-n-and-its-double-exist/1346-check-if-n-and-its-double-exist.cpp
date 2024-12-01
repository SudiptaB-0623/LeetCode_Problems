class Solution 
{
public:
    bool checkIfExist(vector<int>& arr) 
    {
        map<int, int> mpp;
        
        for(auto num : arr)
        {
            if(mpp.find(num*2) != mpp.end() || (num%2==0 && mpp.find(num/2) != mpp.end()))
                return true;
            mpp[num] = 1;
        }
        
        return false;
    }
};