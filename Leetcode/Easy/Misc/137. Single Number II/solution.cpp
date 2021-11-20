class Solution {
public:
    int singleNumber(vector<int>& nums) {
         map<long long,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            long long el = nums[i];
            m[el]++;
        }
        int res;
        for(int i=0;i<nums.size();i++)
        {
            int el = nums[i];
            if(m[el] == 1)
            {
                res=el;
                break;
            }
        }
        return res;
        
    }
};