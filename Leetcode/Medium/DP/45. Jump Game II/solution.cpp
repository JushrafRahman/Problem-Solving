class Solution { //dp top down iterative
public:
    int jump(vector<int>& nums) {
        int sz=  nums.size();
        if(sz == 1)
        {
            return 0; //already in last index
        }
        long long dp[sz+10];
        memset(dp, 0, sizeof dp);
        for(int i = sz-2; i >=0 ; i--) //start from 2nd last indx 
        {
             long long val = nums[i];
            while(i + val >= sz)
            {
                val--;
            }
            long long mini= INT_MAX;
            while((i + val <  sz) && (val > 0))
            {
                mini = min(mini, 1 + dp[ i + val] );
                val--;
                
            }

                dp[i] = mini;       
        }
        return dp[0];
        
    }
};