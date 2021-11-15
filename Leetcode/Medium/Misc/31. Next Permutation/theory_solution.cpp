class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if(nums.size() >= 2)
        {
            int n=nums.size();
            int el,el_idx;
            bool f=false;
            for(int i=n-2; i>=0 ; i--)
            {
                if(nums[i]<nums[i+1])
                {
                    f=true;
                    el=nums[i];
                    el_idx=i;
                    break;

                }
            }
            if(f)
            {
                for(int i=n-1; i>el_idx; i--)
                {
                    if(nums[i]>el)
                    {
                        swap(nums[i],nums[el_idx]);
                        break;
                    }
                }
                reverse(nums.begin()+el_idx+1,nums.end());
            }
            else
            {
                sort(nums.begin(),nums.end());
            }


        }


    }



};
/* 
for example:  1,2,7,6,5,4,3 -> [1,2],[7,6,5,4,3]
In this permutation we can see that we have reached the max suffix for prefix [1,2]. That is, there is no way we can get a greater suffix for [1,2] since the
later elements are in desc order. So we have to change the prefix and the next greater prefix is [1,3] and reverse the remaining elements or sort them in asc order
that is : (init): 1,2,7,6,5,4,3 (find from last the element which breaks the descending order. Here desc order is [7,6,5,4,3] and 2 breaks it. so replace 2
with the first element from the end that is greater than 2, so that it forms the next greater prefix. Here 3 is > 2 so next prefix is [1,3])
so swap (2,3) -> [1,3],[7,6,5,4,2]. Now reverse the remaining to put them in ascending order or just sort the remaining.
so [1,3],[2,4,5,6,7]



*/