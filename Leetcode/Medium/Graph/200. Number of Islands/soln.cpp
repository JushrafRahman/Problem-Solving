class Solution {
public:
    bool vis[310][310] ;
    int dirx[4] = {0,0,1,-1};
    int diry[4] = {1,-1,0,0};
    int numIslands(vector<vector<char>>& grid) {
        memset(vis,0,sizeof vis);
        int res = 0 ;
        for(int i= 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[i].size(); j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& arr, int i, int j)
    {
        vis[i][j] = true;
        
        for(int dir = 0 ;dir<4; dir++)
        {
            int x = i + dirx[dir];
            int y = j + diry[dir];
            if(is_valid(arr,x,y) && (!vis[x][y]))
            {
                if(arr[x][y] == '1'){
                dfs(arr,x,y);
                }
            }
        }  
        
    }
    bool is_valid(vector<vector<char>> &arr, int x, int y)
    {
        if(x>=0 && x<arr.size())
        {
            if(y>=0 && y<arr[x].size())
            {
                return true;
            }
            
        }
        return false;
    }
    
};