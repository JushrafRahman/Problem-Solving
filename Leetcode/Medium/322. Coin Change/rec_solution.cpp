//This is the recursive approach
class Solution
{
public:
    int dp[10010][15];
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof dp);
        pair<int,bool> res= findres(coins.size()-1,amount,coins);
        if(res.second)
        {
            return res.first;
        }
        else
        {
            return -1;
        }
    }
    pair<int,bool> findres(int coinidx,int amount,vector<int> &coins)
    {
        if(amount == 0)
        {
            return make_pair(0,true);
        }
        else if(coinidx<0) //out of bounds
        {
            return make_pair(0,false);
        }
        else if(dp[amount][coinidx]!= -1)
        {
            if(dp[amount][coinidx]==0)
            {
                return make_pair(0,false);
            }
            else
            {
                return make_pair(dp[amount][coinidx],true);
            }

        }
        else if(amount == coins[coinidx]) //might give rte
        {
            return make_pair(1,true);
        }
        else
        {
            pair<int,bool> take,leave;
            int moves=0;
            bool status=false; //whether the amount is breakable or not

            if(coins[coinidx]<= amount) //either take it or leave it
            {
                int tmoves,lmoves;
                take=findres(coinidx,amount-coins[coinidx],coins); //taking
                tmoves=1+take.first;//coin took + returned value

                leave=findres(coinidx-1,amount,coins); //leaving
                lmoves=leave.first;

                if(take.second && leave.second) //both taking , leave breaks down amount
                {
                    moves=min(tmoves,lmoves);
                    status=true;
                }
                else if(take.second)
                {
                    moves=tmoves;
                    status=true;
                }
                else if(leave.second)
                {
                    moves=lmoves;
                    status=true;
                }
                else //either way not possible
                {
                    moves=0;
                    status=false;
                }

            }
            else
            {
                leave=findres(coinidx-1,amount,coins);
                moves=leave.first;
                if(leave.second) //if breakable
                {
                    status=true;
                }
                else
                {
                    moves=0;
                    status=false;
                }

            }

            dp[amount][coinidx]=moves;
            return make_pair(moves,status);
        }

    }
};