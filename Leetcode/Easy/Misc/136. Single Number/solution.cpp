class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
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