class Solution {
private:
    int r,c;
    long long findres = 0;
    int dp[110][110];
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        r = obstacleGrid.size()-1; 
        c = obstacleGrid[0].size()-1;
      if(obstacleGrid[r][c] == 1)
      {
          return 0;
      }
        //memset(dp,-1,sizeof dp);
        for(int i=0; i<obstacleGrid.size(); i++)
        {
            for(int j=0; j<obstacleGrid[i].size(); j++)
            {
                if(obstacleGrid[i][j] == 0 ) //no obstacle
                {
                    dp[i][j] = -1; //soln  not found
                }
                else
                {
                      dp[i][j] = 0; //obstacle
                    
                }
            }
        }
        dp[r][c] = 1 ;
        return checkres(0,0);

    }
    long long checkres(int i,int j)
    {
        if(!isvalid(i,j))
        {
            return dp[i][j]=0;
        }
        else if(dp[i][j]!= -1)
        {
            return dp[i][j];
        }
        long long down = checkres(i+1,j);
        long long right = checkres(i,j+1);
        
        return dp[i][j] = down+right;
    }
    bool isvalid(int i,int j)
    {
        if(i>=0 && i<=r && j>=0 && j<=c)
        {
            return true;
        }
        return false;
    }
};