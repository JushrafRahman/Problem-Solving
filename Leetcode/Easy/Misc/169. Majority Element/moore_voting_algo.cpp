//majority element: element whose frequency > n/2
//so there must be instances of them being adjacent which is why this algo works
//this algo does not find out the max occurring element though
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0, cnt = 1;
        for(int i= 1; i< nums.size(); i++)
        {
            if(nums[i] == nums[maj]) //if same adjacent elements
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if(cnt == 0)//update the maj element which exists only once currently
            {
                maj = i;
                cnt = 1;
            }
        }
        return nums[maj];
    }
};
