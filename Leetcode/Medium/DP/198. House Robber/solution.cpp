class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if( len == 1)
        {
            return nums[0];
        }
        else if (len == 2)
        {
            return max(nums[0],nums[1]);
        }
        else //idea is to travel from the back and keep storing the best solution
        {
            nums[len-2]=max(nums[len-2],nums[len-1]); //second last element will store the max between itself and the last
            
            for(int i=len-3; i>=0; i--)
            {
                int take= nums[i]+nums[i+2]; //take current element + solution of two indexes later
                int leave=nums[i+1]; 
                nums[i]=max(take,leave);
            }

            return nums[0];
        }
    }
};