class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        map<int,map<int,int>> m;
        map<int,bool> already_calc;

        sort(nums.begin(),nums.end());

        vector<vector<int>> finarr;
        if(nums.size()>=3)
        {
            for(int i=0; i<nums.size()-1; i++)
            {
                int el=nums[i];
                if(already_calc[el] == false) //if this element was prev not calc
                {
                    already_calc[el]=true;
                    int l=i+1,r=nums.size()-1,mid,res;

                    while(l<r)
                    {
                        vector<int> x;
                        if(nums[l]+nums[r] == (0-nums[i]))
                        {
                            if(m[el][nums[l]]!=1) //first pos, second pos already not calc
                            {

                                m[el][nums[l]]=1; //calced
                                x.push_back(nums[i]);
                                x.push_back(nums[l]);
                                x.push_back(nums[r]);
                                l++;
                                r--;
                                finarr.push_back(x);
                            }
                            else
                            {
                                l++;
                                r--;
                            }

                        }
                        else if(nums[l]+nums[r] < (0-nums[i]))
                        {
                            l++;
                        }
                        else
                        {
                            r--;
                        }

                    }


                }




            }
        }
        return finarr;

    }
};