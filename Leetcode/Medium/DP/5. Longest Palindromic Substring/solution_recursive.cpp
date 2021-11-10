//getting TLE dont know why will fix it later
#include<bits/stdc++.h>


#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define eps 1e-10
#define endl "\n"
#define kase(ks) cout<<"Case "<<++ks<<":"
#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;
class Solution
{
 public:

     int a=0,b=0,reslen=1;
    string longestPalindrome(string s)
    {
        int arr[1003][1003];
        memset(arr,-1,sizeof arr);
        int len = s.length();
        if(len == 1)
        {
            return s;
        }
        bool x = is_pd(0,len-1,s,arr);
        string str = s.substr(a,reslen);
        return str;

    }
    bool is_pd(int first, int last , string s,int (&dp)[1003][1003])
    {
       // cout<<"current idx: "<<first<<","<<last<<endl;
        if(dp[first][last] != -1) //already calc
        {
         //   cout<<"already calc"<<endl;
            return dp[first][last];
            if(dp[first][last] == 1)
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
         //   cout<<"only char"<<endl;
            dp[first][last]=1;
            return true;
        }
        if((s[first] == s[last] ) && (first + 1 == last)) //no other elements in betn
        {
          //  cout<<"2 chars equal"<<endl;
            dp[first][last] =1 ;
            if(2 > reslen) //2 is the size of this pd
            {
                reslen=2;
                a=first;
                b=last;
            }
            return true;

        }
        if((s[first] == s[last] ) && (is_pd(first+1,last-1,s,dp) == 1 ))
        {
          //  cout<<"yes mid is pd"<<endl;
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
        bool b1 = is_pd(first,last-1,s,dp); //try to see if other substrs have pd or not
        bool b2= is_pd(first+1,last ,s,dp);
        return false; //since initial first,last cant be pd
    }



};
int main()
{
    string in;
    cin>>in;
    Solution a;
    cout<<a.longestPalindrome(in);


    return 0;
}
