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

int n,t;
vector<int> tracks;

struct node{
    int val;
    vector<int> path;

};

node dp[10005][25]; //cap,idx

node findres(int cap, int curidx)
{
    if(cap <=0 || curidx >=t)
    {
        node temp;
        temp.val = 0;
        temp.path.clear();
        return temp;
    }
    else
    {
        node temp2 = dp[cap][curidx];
        if(temp2.val != -1) //already cached
        {
            return temp2;
        }
        else
        {
            if(cap >= tracks[curidx])
            {
                //take
                node take = findres(cap - tracks[curidx], curidx + 1);
                take.val += tracks[curidx];
                take.path.push_back(curidx);

                node leave = findres(cap, curidx + 1);
                if(take.val >= leave.val)
                {
                    return dp[cap][curidx] = take;
                }
                else
                {
                    return dp[cap][curidx]  = leave;
                }

            }
            else
            {
                return dp[cap][curidx] = findres(cap, curidx + 1);
            }

        }
    }
}

void init()
{
    tracks.clear();
    for(int i = 0 ; i < 10005 ; i++)
    {
        for(int j = 0 ;j < 25 ; j++)
        {
            node temp;
            temp.val = -1;
            temp.path.clear();
            dp[i][j] = temp;
        }
    }

}
int main()
{
    while(cin>>n>>t)
    {
        init();
        if((n == 0) ||(t == 0) )//no tracks
        {
            cout<<"sum:0"<<endl;
        }
        else{
        for(int i= 0 ;i <t; i++)
        {
            int num;
            cin>>num;
            tracks.pb(num);
        }

        node res  = findres(n,0);
        for(int i = res.path.size() - 1 ; i >= 0; i--)
        {
            cout<<tracks[res.path[i]]<<" ";
            if(i == 0)
            {
                cout<<"sum:"<<res.val<<endl;
            }
        }
        }
    }


    return 0;
}
