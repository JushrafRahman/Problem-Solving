class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1)
        {
            return true;
        }
        vector<int> exist(sz,0); // 0 = false
        exist[sz-1] = 1; 
        for(int i = sz - 2; i >=0 ;i-- )
        {
            if(nums[i] == 0)
                continue;
            
            if(i + nums[i] >= sz - 1 )
            {
                exist[i] = 1;
            }
            else
            {
                int val = i + nums[i];
                while(val > i)
                {
                    
                    if(exist[val] == 1)
                    {
                        exist[i] = 1;
                        break;
                    }
                    val--;
                }
            }
            
        }
        if(exist[0])
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }
};