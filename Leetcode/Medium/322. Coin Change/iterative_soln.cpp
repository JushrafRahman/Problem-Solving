//iterative approach
class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(),coins.end());
        int dp[amount+5]; //dp[i] means min number of coins to make amount i
        for(int i=0; i<=amount; i++)
        {
            dp[i]=amount+1; //initialize dp with max value
        }
        dp[0]=0;
        for(int money=1; money<=amount; money++)
        {
            for(int i=0; i<coins.size(); i++)
            {
                if(coins[i]>money)
                {
                    break;
                }
                int take=1+dp[money-coins[i]];
                int leave=dp[money];
                dp[money]=min(take,leave);
            }
        }
        if(dp[amount]!=(amount+1))
        {
            return dp[amount];
        }
        return -1;

    }

};
