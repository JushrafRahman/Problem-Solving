class Solution {
private:
    int r,c;
    int dp[210][210];
public:
    int minPathSum(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        memset(dp,-1,sizeof dp);
        return finres(0,0,grid);
        
    }
    int finres(int i,int j,vector<vector<int>>& grid)
    {
        if(!isvalid(i,j))
        {
            return dp[i][j] = INT_MAX;
        }
        if(dp[i][j]!= -1)
        {
            return dp[i][j];
        }
        if((i == (r-1)) && (j == (c-1)))
        {
            return dp[i][j] = grid[i][j];
        }
        int down = finres(i+1,j,grid);
        int right = finres(i,j+1,grid);
        return dp[i][j] = grid[i][j] + min(down,right);
    }
    bool isvalid(int i, int j)
    {
        if(i>=0 && i<r && j>=0 && j<c)
        {
            return true;
        }
        return false;
    }
};