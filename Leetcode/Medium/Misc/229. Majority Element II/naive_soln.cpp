class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int len = nums.size()/3;
        vector<int> res;
        for(auto it = m.begin(); it!= m.end(); it++)
        {
            if(it->second > len)
            {
                res.push_back(it->first);
            }
        }
        return res;
    }
};