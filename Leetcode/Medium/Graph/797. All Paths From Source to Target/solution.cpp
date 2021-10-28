class Solution {
public:
    int source;
    int dest;
    vector<vector<int>>finres; //stores the result vectors
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         source=0;
         dest=graph.size()-1;
         vector<int> x =graph[source]; //adjacent vectors to source
         for(int i=0;i<x.size();i++)
         {
             int v= x[i];
             vector<int>path;
             path.push_back(source); //insert source to the result path
             dfs(v,path,graph); 
         }
         return finres;
    }
    void dfs(int node,vector<int>path,vector<vector<int>>& graph )
    {
        path.push_back(node); //insert node to the result path
        if(node == dest)
        {
            finres.push_back(path); //push path to result
            return;
        }
        vector<int>x =graph[node]; //adjacent nodes list from 'node'

        for(int j=0;j<x.size();j++)
        {
            int v=x[j]; //adjacent node from 'node'
            dfs(v,path,graph);
        }
    }
};