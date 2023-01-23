class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int left = 0;
        int right = arr.size()-1;
        
        for(int i=0;i<arr.size();i++)
        {
            int mid = (left+right)/2;
            
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else
            {
                if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
                {
                    left = mid+1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        return 0;
    }
};