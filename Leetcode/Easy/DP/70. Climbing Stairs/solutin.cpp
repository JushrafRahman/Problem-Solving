class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(50);
        dp[1]=1; dp[2]=2;
        for(int i=3; i<=45 ;i++)
        {
            dp[i]=dp[i-1]+dp[i-2]; 
        }
        return dp[n];

    }
};

/*  Explanation: DP
for n=3 , output = {1,1,1},{1,2},{2,1} so position matters here
we will solve this using memoization
Firsty  solution for n =1 , {1} //we can take only coin 1
solution for n=2 , {1,1} //will take coin 1 first, so  coin sequence will be 1(coin 1) + [2-1] (memoized solution for remaining amount)
		   ,{2} //will take coin 2 first, so coin sequence will be  2(coin 2)+[2-2] (memoized solution for remaining amount)
simply put,
for n=2, we take coin 1 first so req comb = 1+[1] = 1+[{1}] = {1,1}
        now we take coin 2 first so req comb=2+[0]={2}
    so total comb = 2
Solution for n=3 , we take coin 1 first so required combination = 1 + [2] = 1+[{1,1},{2}] = {1,1,1},{1,2} 
		   now we take coin 2 first so req combination = 2+[1] = 2+[{1}] = {2,1}
                  so total comb = 3 
Solution for n=4, we take coin 1 first so 1+[3] = 1+[{1,1,1},{1,2},{2,1}] = {1,1,1,1},{1,1,2},{1,2,1}
            now we take coin 2 first, so req comb = 2+[2] = 2+[{1,1},{2}] = {2+1+1},{2+2}
            so total comb= 5


*/ 
