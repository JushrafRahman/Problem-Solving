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
int t,w,n;
vector<pair<int,int>>treasure;
struct node
{
    int val = 0;
    vector<int> path;
};
struct node dp[40][1005]; //item,cap

node findres(int idx,int cap)
{
    if(idx >= n || cap <= 0)
    {
        node temp;
        temp.val = 0;
        temp.path.clear();
        return temp;
    }
    else
    {
        node temp2 = dp[idx][cap];
        if(temp2.val != -1) //been cached
        {
            //merge and return
            return temp2;
        }
        else //has not been cached
        {
            int cost = 3 * w * treasure[idx].first;
            int value = treasure[idx].second;
            if(cap >= cost)
            {
                node take = findres(idx+1, cap - cost);
                take.val += value;
                take.path.pb(idx);
                node leave = findres(idx+1, cap);
                if(take.val > leave.val)
                {
                    return dp[idx][cap] = take;
                }
                else
                {
                    return dp[idx][cap] = leave;
                }
            }
            else
            {
                return dp[idx][cap] = findres(idx+1, cap);
            }
        }
    }
}
void init()
{
    treasure.clear();
    for(int i = 0 ; i<40; i++)
    {
        for(int j = 0 ; j<1005; j++)
        {
             node temp;
            temp.val = -1; //value not found yet
            temp.path.clear();
            dp[i][j] = temp;
        }
    }

}
int main()
{
    int ks = 0;
    while(cin>>t>>w)
    {
        if(ks)
        {
            cout<<endl;
        }
        init();
        cin>>n;
        rep(i,n)
        {
            int depth, value;
            cin>>depth>>value;
            treasure.pb(mp(depth,value));
        }
        node res;
        res.val = 0;
        res.path.clear();
        res = findres(0,t);
        cout<<res.val<<endl;
        cout<<res.path.size()<<endl;
        sort(res.path.begin(), res.path.end());
     //   reverse(res.path.begin(), res.path.end());
        for(int i = 0 ; i<res.path.size(); i++)
        {
            //cout<<res.path[i]<<" and its corresponding ans = ";
            cout<<treasure[res.path[i]].first<<" "<<treasure[res.path[i]].second<<endl;

        }
      //  cout<<endl;
     ks++;


    }
    return 0;
}
