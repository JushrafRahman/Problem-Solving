class Solution
{
 public:
     int dp[1003][1003];
     int a=0,b=0,reslen=1; //default first element is the longest pd substr
    string longestPalindrome(string s)
    {

        memset(dp,-1,sizeof dp);
        int len = s.length();
        if(len == 1)
        {
            return s;
        }
        bool x = is_pd(0,len-1,s);
        string str = s.substr(a,reslen);
        return str;

    }
    bool is_pd(int first, int last , string &s)
    {

        if(dp[first][last] != -1) //already calc
        {
            return dp[first][last];
            if(dp[first][last] == 1) //yes pd
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if(first == last) //only 1 char
        {
            dp[first][last]=1; //yes pd
            return true;
        }
        if((s[first] == s[last] ) && (first + 1 == last)) //no other elements in betn
        {
            dp[first][last] =1 ;
            if(2 > reslen) //2 is the size of this pd
            {
                reslen=2;
                a=first;
                b=last;
            }
            return true;

        }
        if((s[first] == s[last] ) && (is_pd(first+1,last-1,s) == 1 ))
        {

                dp[first][last] =1;
                int curlen= last-first+1;
                if(curlen>reslen)
                {
                    reslen=curlen;
                    a=first;
                    b=last;
                }
                return true;

        }
        //first , last not equal so no chance of having a pd with them as boundary chars
        dp[first][last] = 0; //so never a pd
        bool b1 = is_pd(first,last-1,s); //try to see if other substrs have pd or not
        bool b2= is_pd(first+1,last ,s);
        return false; //since initial first,last cant be pd
    }



};