class Solution
{
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
    {
        int n=nums1.size();
        map<long long, int>ab;
        map<long long, int> cd;
        for(int i=0 ; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                long long sum=nums1[i]+nums2[j];
                ab[sum]++;
                long long sum2=nums3[i]+nums4[j];
                cd[sum2]++;
            }
        }
        long long res=0;
        for(auto it1=ab.begin(); it1!= ab.end(); it1++)
        {
            long long x=it1->first;
            long long xfreq=it1->second;
            for(auto it2=cd.begin(); it2!= cd.end(); it2++)
            {
                long long y=it2->first;
                long long yfreq=it2->second;
                long long sum=x+y;
                if(sum == 0)
                {
                    long long prod=xfreq*yfreq;
                    res+=prod;

                }
            }

        }
        return res;



    }
};