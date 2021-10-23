class Solution {  //o(n^2)
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxi=1;
        vector<int> dp(nums.size());
        for(int i=0;i<dp.size();i++)
        {
            dp[i]=1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if((nums[j]>nums[i])&&(dp[i]+1>dp[j]))
                {
                    dp[j]=dp[i]+1;
                    maxi=max(maxi,dp[j]);

                }
            }

        }
        return maxi;

    }
};