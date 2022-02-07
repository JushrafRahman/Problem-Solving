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

int c;
vector<pair<int,int>>comp_loc;

struct node  
{
    double dis;
    int edge[10][10]; //edge between i and j computer
    double edgeval[10][10];
    void init()
    {
        dis = 0;
        memset(edge, -1, sizeof(edge));
        memset(edgeval, 0, sizeof(edgeval));
    }

};
double calculate_dis(int prev_idx,int cur_idx)
{
    int x = comp_loc[prev_idx].first;
    int y = comp_loc[prev_idx].second;
    int a = comp_loc[cur_idx].first;
    int b = comp_loc[cur_idx].second;
    double dis = sqrt(pow(x-a,2)+pow(y-b,2));

    return dis;
}
node make_connection(node prev,int prev_idx,int cur_idx, vector<bool> &vis,int cur_conn)
{

    cur_conn++; //connection between prev an cur
    double dis_between  = calculate_dis(prev_idx,cur_idx)+16; 

    prev.edgeval[prev_idx][cur_idx] = dis_between;
    prev.edgeval[cur_idx][prev_idx] = dis_between;

    prev.dis += dis_between;
    prev.edge[prev_idx][cur_idx] = 1; //bi-directional edge between them
    prev.edge[cur_idx][prev_idx] = 1;

    if(cur_conn == (c-1)) //all connections made
    {
        return prev;
    }

    node res3;
    res3.dis = INT_MAX;

    for(int i = 0; i < c; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            node temp3 = make_connection(prev,cur_idx,i,vis,cur_conn);
            vis[i] = false;
            if(temp3.dis < res3.dis)
            {
                res3 = temp3;
            }
        }

    }
    return res3;

}
node make_first_node(int comp_idx, vector<bool> &vis)
{
    node start;
    start.init();

    node res2;
    res2.dis = INT_MAX;

    for(int i = 0; i<c; i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            node temp2 = make_connection(start,comp_idx,i,vis,0);
            vis[i] = false;
            if(temp2.dis < res2.dis)
            {
                res2 = temp2;
            }
        }
    }
    return res2;

}

void printres(int root, node res, vector<bool> &vis2)
{
    vis2[root] = true;
    int next;
    bool f = false;
    for(int i = 0; i<c; i++)
    {
        if(res.edgeval[root][i] != 0)
        {
            if(!vis2[i])
            {
                f = true;
                next = i;
                break;
            }
        }
    }
    if(f)
    {
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",comp_loc[root].first,comp_loc[root].second,comp_loc[next].first,comp_loc[next].second,res.edgeval[root][next]);
        printres(next,res,vis2);
    }
}
int main()
{
    fast;
    int ks = 0;
    while((cin>>c)&&(c))
    {
        comp_loc.clear();
        for(int i= 0 ; i<c; i++)
        {
            int x,y;
            cin>>x>>y;
            comp_loc.pb(mp(x,y));
        }
        vector<bool> vis(c);

        node res;
        res.dis = INT_MAX;
        for(int i= 0 ; i<c; i++)
        {
            if(!vis[i])
            {
                vis[i] = true;

                node temp = make_first_node(i,vis);
                vis[i] = false;

                if(temp.dis < res.dis)
                {
                    res = temp; //new res
                }
            }
        }
        vector<bool> vis2(c);
        int root;
        for(int i = 0 ; i<c; i++)
        {
            int cnt = 0;
            for(int j = 0; j< c; j++)
            {
                if(res.edgeval[i][j] != 0)
                {
                    cnt++;
                }
            }
            if(cnt == 1)
            {
                root = i;
                break;
            }
        }
        printf("**********************************************************\n");
        printf("Network #%d\n",++ks);
        printres(root,res,vis2);
        printf("Number of feet of cable required is %.2lf.\n",res.dis);


    }

    return 0;
}
