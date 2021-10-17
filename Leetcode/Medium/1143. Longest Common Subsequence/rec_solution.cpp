class Solution
{
public:
    int dp[1000][1000];
    int l1,l2;
    string s,t;
    int longestCommonSubsequence(string text1, string text2)
    {
        l1=text1.length();
        l2=text2.length();
        s=text1;
        t=text2;
        memset(dp,-1,sizeof dp);
        int res=lcs(0,0);
        return res;
    }
    int lcs(int i,int j)
    {
        if(i>=l1 || j>=l2)
        {
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i] == t[j])
        {
            dp[i][j]=1+lcs(i+1,j+1);
            return dp[i][j];
        }
        else
        {
            dp[i][j]=max(lcs(i,j+1),lcs(i+1,j));
            return dp[i][j];
        }

    }
};