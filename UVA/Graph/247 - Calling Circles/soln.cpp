#include <bits/stdc++.h> //Soln = SCC(strongly connected component)

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int nodes,edges;
unordered_map<string,vector<string>> g;
unordered_map<string,vector<string>> rev_g;
unordered_map<string,int> final_push;

unordered_map<string,int> start_times;
unordered_map<string,int> fin_times; //sort this in decreasing order and then do reverse graph

vector<vector<string>> ult_res;

vector<pair<string,int>> vec_fin;
map<string,bool>vis;


int curtime = 0;
bool f(const pair<string,int> &a, const pair<string,int> &b)
{
    return (a.second>b.second);
}

void dfs_new(string source,vector<string> &cur_path) //on reverse graph
{
    vis[source] = true;
    if(final_push[source] != 1)
    {
        cur_path.pb(source);
        final_push[source] = 1;
    }
    vector<string> children  = rev_g[source];

    for(int i=0; i<children.size(); i++)
    {
        string v = children[i];
        if(vis[v]!=1) //if child not visited
        {
            dfs_new(v,cur_path);

        }


    }
}
void dfs(string source)
{
    vis[source] =1 ;
   // int start = curtime;
    start_times[source] = curtime;
  //  cout<<"currently at source = "<<source<<" and st = "<<start_times[source]<<endl;
    curtime++;

    vector<string>children = g[source];
    for(int i= 0 ; i<children.size(); i++)
    {
        string v = children[i];
        if(vis[v]!=1) //if child not visited
        {
            dfs(v);

        }
    }
  //  int fin = curtime;
    fin_times[source] = curtime;
    curtime++;
  //  cout<<"currently at source = "<<source<<" and fin t = "<<fin_times[source]<<endl;
  //  times[source] = mp(start,fin);


}
void init()
{
    curtime = 0;
    ult_res.clear();
    g.clear();
    rev_g.clear();
    final_push.clear();
    vec_fin.clear();
    vis.clear();
    start_times.clear();
    fin_times.clear();
}

int main()
{
    fast;
    int ks = 1;

    while((cin>>nodes>>edges)) //&& (nodes!=0))
    {
        if(nodes == 0 && edges ==0)
        {
            break;
        }
        if(ks>0)
        {
            cout<<endl;
        }
        init();
        for(int i = 0 ; i<edges ; i++)
        {
            string a,b;
            cin>>a>>b;
            g[a].pb(b); //a calls b
            rev_g[b].pb(a); //reverse graph
        }

        int last_time = 0;
        for(auto it = g.begin(); it!=g.end(); it++) //calculate start and finish time for all nodes;
        {
            string u = it->first;
            if(vis[u]!=1)
            {
                dfs(u);
                //curtime++;
            }
        }
        for(auto it = fin_times.begin(); it!= fin_times.end(); it++)
        {
            string name = it->first;
            int fin_val = it->second;
            vec_fin.pb(mp(name,fin_val));
        }
        sort(vec_fin.begin(), vec_fin.end(),f) ; //sort this in decreasing finish times

        //revamp vis
        for(auto it = vis.begin(); it!= vis.end(); it++)
        {
            string x = it->first;
            vis[x] = false; //memset
        }

        for(int i =0 ; i<vec_fin.size(); i++)
        {
            //cout<<vec_fin[i].first<<" and fin time = "<<vec_fin[i].second<<endl;
            string u  = vec_fin[i].first;
            if(vis[u]!=1) // not vis
            {
                vector<string> temp_path;
                temp_path.pb(u);
                final_push[u] = 1; //
                dfs_new(u,temp_path);
                ult_res.pb(temp_path);

            }

        }
        cout<<"Calling circles for data set "<<ks++<<":"<<endl;
        for(int i= 0; i<ult_res.size(); i++)
        {
            for(int j = 0; j<ult_res[i].size(); j++)
            {
                if(j>0)
                {
                    cout<<", "<<ult_res[i][j];
                }
                else
                {
                cout<<ult_res[i][j];
                }

            }
            cout<<endl;
        }
       // cout<<endl;
    }





    return 0;
}
