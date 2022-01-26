#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; i++ )
#define kase(ks) cout<<"Case "<<++ks<<": "
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int items,persons;
int i_price[1005];
int i_weight[1005];
ll dp[1005][1005]; //item idx, capacity

ll findres(int item_idx,int capacity)
{
    if(item_idx >= items || capacity <=0)
    {
        return 0;
    }
    //dp
    if(dp[item_idx][capacity] != -1) //precalculated
    {
        return dp[item_idx][capacity];
    }
    if(i_weight[item_idx] <= capacity) //can afford
    {
        //take or leave
        ll take = i_price[item_idx] + findres(item_idx+1, capacity - i_weight[item_idx]);
        ll leave = findres(item_idx+1,capacity);
        return dp[item_idx][capacity] = max(take,leave);
    }
    else //only leave
    {
        return dp[item_idx][capacity] = findres(item_idx + 1,capacity);

    }

}

void init()
{
    memset(i_price,0,sizeof i_price);
    memset(i_weight,0,sizeof i_weight);
    memset(dp, -1, sizeof dp);

}
int main()
{
    fast;
    int tc;
    cin>>tc;
    while(tc--)
    {
        init();
        cin>>items;
        rep(i,items)
        {
            cin>>i_price[i]>>i_weight[i];
        }
        cin>>persons;
        vector<int> capacity(persons);
        ll res = 0;
        rep(i,persons)
        {
            cin>>capacity[i];
            res += findres(0,capacity[i]);
        }
        cout<<res<<endl;

    }
    return 0;
}
