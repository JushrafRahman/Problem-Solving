class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int el = nums[i];
            if(m[el] == 1)
            {
                if(res.size() >= 2)
                {
                break;
                }
                else
                    res.push_back(el);
                    
            }
        }
        return res;
        
    }
};