class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, -1));
        if(len == 1)
        {
            return 1;
        }
        return findres(0,len-1,s,dp);


    }
    int findres(int i,int j ,string &s,vector<vector<int>> &dp)
    {
        if(i>j) //invalid index
        {
            return dp[i][j] = 0;
        }
        if(dp[i][j] != -1) //already calc
        {
            return dp[i][j];
        }
        if(i == j)
        {
            return dp[i][j] = 1;
        }
        if(s[i] == s[j])
        {
            return dp[i][j] = 2 + findres(i+1,j-1,s,dp);
        }
        else
        {
            int  left = findres(i,j-1,s,dp);
            int right = findres(i+1,j,s,dp);
            return dp[i][j] =max(left,right);
        }
    }


};