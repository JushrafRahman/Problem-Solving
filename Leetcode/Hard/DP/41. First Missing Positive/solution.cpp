class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
//        int res=1;
        int sz=nums.size();
        int f=0;
        int res=1;
        for(int i=1;i<=301;i++)
        {
            int l=0,r=sz-1,mid;
            f=0;
            while(l<=r)
            {
                mid=(l+r)/2;
                if(nums[mid]==i)
                {
                    f=1;
                    break;
                }
                if(nums[mid]<i)
                {
                    l=mid+1;
                }
                else if(nums[mid]>i)
                {
                    r=mid-1;
                }

            }
            if(f==0) //that no wasnt found
            {
                res=i;
                break;

            }
        }
        return res;


    }
};