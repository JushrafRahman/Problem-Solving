class Solution
{
private:
    const int sz = 1e5+10;
    vector<int> g[100010];
    vector<int> par[100010];
    vector<int> allnodes;
    vector<int>finres;
    bool vis[100010];
    int res = 0;
    int nodes;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        nodes = numCourses;
        for(int i=0; i<prerequisites.size(); i++) //construct the graph
        {
            vector<int> vec = prerequisites[i];
            int a = vec[0];
            int b = vec[1];
            par[a].push_back(b); //b -> a
            g[b].push_back(a); // b -> a
        }
        topsort();
        reverse(allnodes.begin(),allnodes.end()); //reverse

        memset(vis,0,sizeof vis);
        for(int i=0; i<allnodes.size(); i++)
        {

            if(!vis[allnodes[i]]) //check it
            {
                last_dfs(allnodes[i]);
            }
        }
        if(res == numCourses)
        {
            return finres;
        }
        else
        {
            vector<int> emty;
            return emty;
        }
        


    }
    void last_dfs(int u)
    {
        bool allparvis = true;
        for(int i=0 ; i<par[u].size(); i++)
        {

            int parent = par[u][i];
            if(!vis[parent])
            {
                allparvis =false;
                break;
            }
        }
        if(allparvis)
        {
            vis[u] = true;
            finres.push_back(u);
            res++;
            for(int j = 0; j<g[u].size(); j++)
            {
                int child = g[u][j];
                if(!vis[child])
                {
                    last_dfs(child);
                }
            }
        }
    }
    void topsort()
    {
        for(int i = 0 ; i<nodes; i++)
        {
            if(!vis[i])
            {
                dfs_ts(i);
            }
        }
    }
    void dfs_ts(int u)
    {
        vis[u] = true;
        for(int i = 0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {
                dfs_ts(v);
            }
        }
        allnodes.push_back(u); //after visiting all its child push it to the stack
    }
    void init()
    {
        memset(vis,0,sizeof vis);
        res=0;
    }
};