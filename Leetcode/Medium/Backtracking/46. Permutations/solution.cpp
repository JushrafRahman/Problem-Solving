class Solution {
private:
    int sz;
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        res.clear();
        vector<bool> taken (sz,false); // initialize it to false
        if(sz == 1)
        {
            res.push_back(nums);
            return res;
        }
        vector<int> cur_arr;
        for(int i=0; i<sz ;i++)
        {
          func(i,cur_arr,taken,nums);        
        }
        return res;
        
    }
    void func(int cur_idx, vector<int> cur_arr, vector<bool> taken, vector<int> & arr)
    {
        cur_arr.push_back(arr[cur_idx]);
        taken[cur_idx] = true;
        
        if(cur_arr.size() ==  sz )
        {
            res.push_back(cur_arr);
            return ;
        }
        if(cur_arr.size() > sz )
        {
            return;
        }
        for(int i=0 ; i<sz; i++)
        {
            if(!taken[i])
            {
                //take
                func(i,cur_arr,taken,arr);
            }
        }
        
        
    }
};