#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
int nodes;
vector<int> g[210];
bool vis[210];
int par[210];
int color[210];

bool bfs(int source)
{
    bool flag = true;
    queue<int> q;
    q.push(source);
    color[source] = 0;
    while(!q.empty())
    {
        int u =q.front();
        q.pop();
        vis[u] = true;
        for(int i= 0 ;i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {

                par[v] = u; //parent of v is u
                q.push(v);
                if(color[u] == 0) //if color of parent is 0
                {
                    color[v] = 1;
                }
                else //if parent is 1
                {
                    color[v] = 0;
                }
            }
            else //already vis so check if same color
            {
                if(color[v] == color[u])
                {
                    flag = false;
                    break;
                }

            }
        }
    }
    return flag;

}

void init()
{
    for(int i=0 ;i<=200; i++)
    {
        g[i].clear();
    }
    memset(vis,0,sizeof vis);
    memset(par,-1,sizeof par);
    memset(color,0,sizeof color);


}
int main()
{
    while((cin>>nodes) &&(nodes))
    {
        init();
        int edges;
        cin>>edges;
        for(int i=0; i<edges; i++)
        {
            int a,b;
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
        if(bfs(0)) //start from node 0
        {
            cout<<"BICOLORABLE."<<endl;
        }
        else
        {
            cout<<"NOT BICOLORABLE."<<endl;
        }

    }






    return 0;
}
