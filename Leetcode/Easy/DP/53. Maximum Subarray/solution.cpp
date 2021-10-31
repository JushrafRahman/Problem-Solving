class Solution { //kadane's algo
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0]; //considering first element to be the result;
        
        for(int i=1; i<nums.size(); i++)
        {
            nums[i]=max(nums[i], nums[i]+nums[i-1]); //element is the max of itself or the sum with the previous element / like dp technique
            res=max(res,nums[i]);
        }
        return res; 

        
    }
};