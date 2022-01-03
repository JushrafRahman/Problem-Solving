class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curidx = 0 ;
        int zero_cnt = 0;
        for(int i =0 ; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zero_cnt++;
            }
            else
            {
                 nums[curidx] = nums[i];
                curidx++;
            }
        }
        while(zero_cnt)
        {
            nums[curidx++] = 0;
            zero_cnt--;
        }
        
    }
};