class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int size=nums1.size()+nums2.size();
        int a=0,b=0,c=0,val1=0,val2=0;
        double ans;
        
        if(nums1.size()==0 && nums2.size()==0)
            return 0;
        if(nums1.size()==0 && nums2.size()!=0)
        {
            cout<<"**"<<1;
            if(nums2.size()%2==0)
            {
                cout<<"**"<<17;
                a=nums2.size()/2;
                b=a-1;
                ans=(nums2[b]+nums2[a])/2.00;
                return ans;
            }
            else
            {
                cout<<"**"<<18;
                b=nums2.size()/2;
                ans=nums2[b];
                return ans;
            }
                
        }
        if(nums1.size()!=0 && nums2.size()==0)
        {
            if(nums1.size()%2==0)
            {
                cout<<"**"<<2;
                a=nums1.size()/2;
                b=a-1;
                ans=(nums1[a]+nums1[b])/2.00;
                return ans;
            }
            else
            {
                cout<<"**"<<3;
                a=nums1.size()/2;
                ans=nums1[a];
                return ans;
            }
                
        }
        
        for(int i=0;i<=size/2;i++)
        {
            if(a>=nums1.size())
            {
                cout<<"**"<<4;
                c=b;
                val2=val1;
                val1=nums2[b];
                b++;
            }
            else if(b>=nums2.size())
            {
                cout<<"**"<<5;
                c=a;
                val2=val1;
                val1=nums1[a];
                a++;
            }
            else if(nums1[a]<nums2[b])
            {
                cout<<"**"<<6;
                c=a;
                val2=val1;
                val1=nums1[a];
                a++;
                cout<<endl<<"a="<<a<<" val1="<<val1<<" val2="<<val2<<endl;
            }
            else if(nums1[a]>=nums2[b])
            {
                cout<<"**"<<7;
                c=b;
                val2=val1;
                val1=nums2[b];
                b++;
            }
        }
        cout<<"##"<<val1+val2;
        if(size%2==0)
            ans=(val1+val2)/2.00;
        else
            ans=val1;
        
        return ans;
    }
};