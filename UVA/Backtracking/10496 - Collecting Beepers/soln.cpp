#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<pair<int,int>>beeper_pos;
bool vis[25];
int r,c;
int totbeep;
int finres;
int sx,sy; //start position
void dfs(int posx,int posy,int pathlen,int curbeep)
{
    if(curbeep == totbeep) //calculate returning distance
    {
        int ret_dis = abs(sx-posx) + abs(sy - posy); //min 2d distance from main source
        ret_dis += pathlen;
        finres=min(finres,ret_dis);
    }
    else
    {
        for(int i =0 ; i<totbeep; i++)
        {
            if(!vis[i]) //if beeper not vis
            {
                vis[i] = true; //make it vis
                int beepx = beeper_pos[i].first;
                int beepy = beeper_pos[i].second;
                int len = abs(posx - beepx) + abs(posy - beepy); //shortest 2d distance from given source to current beeper
                dfs(beepx, beepy, pathlen + len, curbeep + 1);
                vis[i] = false; //make it false to backtrack


            }
        }
    }
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        memset(vis,0,sizeof vis);
        finres = INT_MAX;
        beeper_pos.clear();
        cin>>r>>c;
        cin>>sx>>sy;
        cin>>totbeep;
        for(int i=0; i<totbeep; i++)
        {
            int a,b;
            cin>>a>>b;
            beeper_pos.pb(mp(a,b)); //inserting beeper position
        }
        dfs(sx,sy,0,0);
        cout<<"The shortest path has length "<<finres<<endl;

    }



}
