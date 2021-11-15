class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
       int iter=0;
        do{
            if(iter)
            {
                break;
            }
            iter++;

        }while(next_permutation(nums.begin(), nums.end()));


    }

};
