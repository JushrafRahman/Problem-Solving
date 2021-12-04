
class Solution {
private:
    int len1,len2,maxlen;
    int dp[505][505];
public:
    int minDistance(string word1, string word2)
    {
        len1 = word1.length();
        len2 = word2.length();
        memset(dp, -1, sizeof dp);

        return findres(word1, word2,0,0,0,0);
    }
    int findres(string &s1,string &s2, int i, int j,int ins, int del)
    {
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if(i >= len1 || j>=len2)
        {
            int curlen1 = len1 - del + ins;
            int dif = abs(curlen1 - len2);
            return dp[i][j] = dif;

        }
        else
        {
            if(s1[i] == s2[j])
            {
                return dp[i][j] = findres(s1 , s2 , i+1, j+1,ins,del);
            }
            else
            {
                int ins_op = 1 + findres(s1,s2,i,j+1,ins+1,del);
                int rep_op = 1 + findres(s1,s2,i+1,j+1,ins,del);
                int del_op = 1 + findres(s1,s2,i+1,j,ins,del+1);
                return dp[i][j] = min(ins_op, min(rep_op,del_op));
            }
        }
    }

};