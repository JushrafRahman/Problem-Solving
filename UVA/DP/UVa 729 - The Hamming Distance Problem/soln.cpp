#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define mp make_pair
#define rep(i,n) for(int i = 0; i < n; i++ )
#define kase(ks) cout<<"Case "<<++ks<<": "
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int n,h;
vector<string> dp[20][20]; //pos,ones

vector<string> findres(string cur, int curidx, int ones)
{
    vector<string> test = dp[curidx][ones];
    if(!test.empty())
    {
        return test;
    }
    else
    {

        if(ones == h)
        {
            vector<string> res;
            res.pb(cur);
            return dp[curidx][ones] = res ;
        }
        if(curidx == (n-1)) //last position
        {
            if(ones == (h-1)) //one short of req
            {
                vector<string> res;
                res.pb("1");
                return dp[curidx][ones] =res;

            }
            else
            {
                vector<string>res; //empty string
                res.clear();
                return dp[curidx][ones] =res;
            }
        }
        else
        {
            //at idx curx, so make it 1 or leave
            char make_conc = '1',leave_conc = '0';
            string temp =  cur.substr(0, n - (curidx + 1));
            vector<string> make = findres(temp, curidx + 1, ones + 1);
            if(!make.empty())
            {
                for(int i= 0 ; i<make.size(); i++)
                {
                    make[i] +=make_conc;
                }
            }

            vector<string> leave = findres(cur, curidx + 1, ones);
            if(!leave.empty())
            {
                for(int i=0; i < leave.size(); i++)
                {
                    leave[i] += leave_conc;
                }
            }
            if((!make.empty()) && (!leave.empty())) //both has values
            {
                for(int i = 0; i< leave.size(); i++)
                {
                    make.pb(leave[i]); //pushing all leaves to the end of make
                }
                return dp[curidx][ones] =make;
            }
            else if(!make.empty()) //only make has values
            {
                return dp[curidx][ones] =make;
            }
            else if(!leave.empty()) //only leave has values
            {
                return dp[curidx][ones] =leave;
            }
            else //all empty
            {
                vector<string> res;
                res.clear();
                return dp[curidx][ones] =res;  //so return an empty string
            }
        }
    }
}
void init()
{
    for(int i=0 ; i<20; i++)
    {
        for(int j = 0; j<20 ; j++)
        {
            vector<string> temp;
            temp.clear();
            dp[i][j] = temp;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int ks = 0;
    while(t--)
    {
        fast;
        init();
        if(ks>0)
        {
            cout<<endl;
        }
        cin>>n>>h;
        string cur="";
        for(int i=0; i<n; i++)
        {
            cur+='0';
        }
        vector<string> res  =findres(cur,0,0);
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++)
        {
            cout<<res[i]<<endl;
        }
        ks++;

    }

    return 0;
}
