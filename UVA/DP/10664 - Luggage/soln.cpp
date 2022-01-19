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
unordered_map<int, unordered_map<int,unordered_map<int,bool>>>dp;
int last;
bool mainres  = false;
bool findres(int sum1,int sum2,int idx, vi &vec)
{
    if(mainres)
    {
        return true;
    }
    else
    {
        if(idx == last) //whole array traversed
        {
            bool res = true;
            if(sum1 != sum2)
            {
                res  = false;
            }
            if(res)
            {
                mainres = true;
            }
            return dp[sum1][sum2][idx] = res;

        }
        if(idx<last) //valid index
        {
            if(dp.count(sum1)&& dp[sum1].count(sum2)&& dp[sum1][sum2].count(idx))
            {
                return dp[sum1][sum2][idx];
            }
            if(dp.count(sum2) && dp[sum2].count(sum1) && dp[sum2][sum1].count(idx))
            {
                return dp[sum2][sum1][idx];
            }
            bool  s1_take = false, s2_take = false;
            s1_take = findres(sum1+vec[idx],sum2,idx+1,vec);
            s2_take  = findres(sum1, sum2 + vec[idx], idx+1, vec);
            if(s1_take|| s2_take) //if anyone true
            {
                return dp[sum1][sum2][idx]  = true;
            }
            else
            {
                return dp[sum1][sum2][idx] = false;
            }
        }
        else
        {
            return false;
        }
    }

}
int main()
{
    fast;
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--)
    {
        mainres = false;
        dp.clear();
        vi arr;
        string s,temp;
        getline(cin,s);
        istringstream is(s);
        while(is>>temp)
        {
            int num = stoi(temp);
            arr.pb(num);
        }
        last = arr.size();
        if(findres(0,0,0,arr))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }


    }
    return 0;
}
