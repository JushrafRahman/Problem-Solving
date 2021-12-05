class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r = nums.size()-1;
        bool found = false;
        int l2,r2,resx,resy,mid;
        vector<int> finres;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(nums[mid] == target)
            {
                found = true;
                r = mid - 1;
                l2 = mid;
            }
            else if(nums[mid] > target)
            {
                r= mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        resx = l2;
        if(found)
        {
            r = nums.size()-1;
            while(l2<=r)
            {
                 mid=(l2+r)/2;
            if(nums[mid] == target)
            {
        
                l2 = mid+1;
                r2 = mid;
            }
            else if(nums[mid] > target)
            {
                r= mid-1;
            }
            else
            {
                l2 = mid+1;
            }
            }
            resy = r2;
            finres.push_back(resx);
            finres.push_back(resy);                
                
        }
        else{
        finres.push_back(-1);
        finres.push_back(-1);
        }
        return finres;
        
        
    }
};