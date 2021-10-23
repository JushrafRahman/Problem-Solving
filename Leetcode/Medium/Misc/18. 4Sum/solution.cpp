class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());

        map<long long, map<long long, map<long long,long long>> > m;
        map<long long,long long>firstpos;
        vector<vector<int>> finarr;
        if(nums.size()>=4)
        {

            for(int i=0; i<nums.size()-3; i++)
            {

                int a=nums[i];
                if(firstpos[a]!=1)
                {
                    firstpos[a]=1;
                    for(int j=i+1; j<nums.size()-2; j++)
                    {
                        int b=nums[j];
                        int l=j+1,r=nums.size()-1;
                        while(l<r)
                        {
                            vector<int> x;
                            long long sum= (long long)a+(long long)b+(long long)nums[l]+(long long)nums[r];
                            if(sum == target)
                            {
                                if(m[a][b][nums[l]] != 1)
                                {
                                    m[a][b][nums[l]] = 1;
                                    x.push_back(a);
                                    x.push_back(b);
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
                            else if(sum < target)
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
        }
        return finarr;

    }
};