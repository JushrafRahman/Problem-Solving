class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int>m;
        for(int i=0 ; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int idx = 0, maj,cnt=1;
        for(auto it = m.begin(); it!= m.end(); it++)
        {
            if(idx == 0)
            {
                maj = it->first;
                cnt = it->second;
            }
            else{
              if(it->second > cnt)
              {
                  cnt = it->second;
                  maj = it->first;
              }
            }
            idx++;
        }
        return maj;
    }
};