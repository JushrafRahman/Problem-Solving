class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1,c1,m2,c2;
        c1 = c2 = 0;
        m1 = m2 = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == m1)
            {
                c1++;
            }
            else if(nums[i] == m2)
            {
                c2++;
            }
            else //does not match any 
            {
                if(c1 == 0) //replace
                {
                    c1 = 1;
                    m1 = nums[i];
                }
                else if(c2 == 0)//replace
                {
                    c2 = 1;
                    m2 = nums[i];
                }
                else
                {
                    c1--;
                    c2--;
                }

            }
        }
        vector<int> res = findFreq(m1,m2,nums);
        return res;
    }
    vector<int> findFreq(int m1, int m2, vector<int> &nums)
    {
        int req = nums.size()/3 + 1;
        int c1 = 0,c2 = 0;
        for(int i= 0 ; i<nums.size(); i++)
        {
            if(nums[i] == m1)
            {
                c1++;
            }
            else if(nums[i] == m2)
            {
                c2++;
            }
        }
        vector<int> res;
        if(c1 >= req)
        {
            res.push_back(m1);
        }
        if(c2 >= req)
        {
            res.push_back(m2);
        }
        return res;
    
    }
    
};