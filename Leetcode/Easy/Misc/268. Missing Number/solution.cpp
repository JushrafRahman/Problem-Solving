class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i != nums[i])
            {
                res = i;
                break;
            }
        }
        return res;
    }
};