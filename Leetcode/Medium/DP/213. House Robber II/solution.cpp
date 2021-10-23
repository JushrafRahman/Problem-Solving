class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int len=nums.size();
        if(len == 1)
        {
            return nums[0];
        }
        else if(len <= 3)
        {
            int maxi=-1;
            for(int i=0; i<len; i++)
            {
                maxi=max(maxi,nums[i]);
            }
            return maxi;
        }
        else
        {
            vector<int> wfirst,wlast;
            wfirst.assign(nums.begin(),nums.end()-1); //new array without last element
            wlast.assign(nums.begin()+1,nums.end()); //new array without first element

             int resf=func(wfirst); //optimal solution of array with first element and without last  

            int resl=func(wlast);//optimal solution of array with last element and without first  

            int res=max(resf,resl); //max of the two
            return res;

        }


    }
    int func(vector<int> arr)
    {
        int len=arr.size();
        if(len == 1)
        {
            return arr[0];
        }
        else if(len == 2)
        {
            return max(arr[0],arr[1]);

        }
        else
        {
            arr[len-2]=max(arr[len-2],arr[len-1]);
            for(int i=len-3; i>=0 ; i--)
            {
                arr[i]=max(arr[i]+arr[i+2],arr[i+1]);
            }
            return arr[0];
        }
    }
    void printarr(vector<int> vec)
    {
        for(int i=0; i<vec.size(); i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<endl;

    }
};