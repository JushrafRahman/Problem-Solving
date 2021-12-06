class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size()-1;
        //nums[0] will contain the lowest val of max sub part
        int mid;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid]<nums[0])
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
            
        }
        //r will contain the idx of highest value of max subpart
        //0 -> r max subpart
        //r+1 -> len - 1 min subpart
        int len = nums.size()-1;
        if(target >= nums[0] && target <= nums[r] )
        {
            return bin_srch(nums,target,0,r);
        }
        else
        {
            return bin_srch(nums,target,r+1,len);
        }
        
        
    }
    int bin_srch(vector<int>& arr, int target,int lo ,int hi)
    {
        int mid,res;
        bool found = false;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            if(arr[mid] == target)
            {
                found =true;
                res = mid;
                break;
            }
            else if(arr[mid] > target)
            {
                hi = mid-1;
            }
            else
            {
                lo = mid +1;
            }
        }
        if(found)
        {
            return res;
        }
        return -1;
        
    }
};