class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int sz  = nums.size();
        mergesort(0,sz-1,nums);

    }
    void mergesort(int p, int q, vector<int> &nums)
    {
        if(p<q)
        {
            int mid = (p+q)/2;
            mergesort(p,mid,nums);
            mergesort(mid+1,q,nums);
            merge_new(p,mid,q,nums);
        }
    }
    void merge_new(int p,int mid, int q, vector<int> &nums)
    {
        int sz1 = mid - p + 1;
        int sz2 = q- mid;
        vector<int> left(sz1+1);
        vector<int> right(sz2+1);
        int temp = p;
        for(int i = 0 ; i <sz1; i++)
        {
            left[i] = nums[temp++];
        }
        left[sz1] = INT_MAX;
        temp = mid+1;
        for(int i = 0; i <sz2; i++)
        {
            right[i] = nums[temp++];
        }
        right[sz2] = INT_MAX;
        int tot = q - p + 1;
        int i,j,k;
        i  = j = k = 0;
        for(int iter = 0 ; iter < tot; iter++)
        {
            if(left[i]<= right[j])
            {
                nums[p+iter] = left[i];
                i++;
            }
            else
            {
                nums[p+iter] = right[j];
                j++;
            }

        }

    }

};