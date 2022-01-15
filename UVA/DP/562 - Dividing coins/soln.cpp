#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int totcoins;
int coins[105];
unordered_map<ll,unordered_map<ll,ll>>dp; //first person, second person, next coin

ll checkres(ll asum, ll bsum,int next_idx)
{
    if((dp.count(asum)) && (dp[asum].count(bsum)))
    {
        return dp[asum][bsum];
    }
    else if(dp.count(bsum) && (dp[bsum].count(asum)))
    {
        return dp[bsum][asum];
    }
    if(next_idx == totcoins) //calculate res
    {
        ll dif = abs(asum - bsum);
        return dp[asum][bsum] = dif;
    }
    else
    {
        //a take
       ll atake = checkres(asum+coins[next_idx],bsum,next_idx+1);
        //btake
       ll btake = checkres(asum,bsum+coins[next_idx],next_idx+1);
       ll cur_res = min(atake,btake);
       return dp[asum][bsum] = cur_res;
    }

}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        dp.clear();
        cin>>totcoins;
        for(int i = 0; i<totcoins; i++ )
        {
            cin>>coins[i];
        }
        cout<<checkres(0,0,0)<<endl;

    }
    return 0;
}