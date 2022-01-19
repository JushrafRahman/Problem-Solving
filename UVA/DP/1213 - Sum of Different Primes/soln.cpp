#include <bits/stdc++.h>

#define ll long long
#define endl "\n"
#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<int>primes;
bool isprime[2000];
int primes_sz;
int k,n;
ll dp[1125][16][306]; //amount, coins, prime_idx

void sieve()
{
    memset(isprime,1,sizeof isprime); //all numbers are prime
    isprime[0] = isprime[1] = false;
    for(int i=2; i<2000; i++)
    {
        if(isprime[i]) //that number is prime
        {
            primes.pb(i); //pushing the prime numbers
            for(int j = i*i; j<2000; j+=i)
            {
                isprime[j] = false;
            }
        }
    }


}
ll findres(int amount, int coins, int prime_idx)
{
    if(amount>=0 && coins>=0 && prime_idx<primes_sz) //valid indexes
    {
        if(dp[amount][coins][prime_idx] != -1)
        {
            return dp[amount][coins][prime_idx];
        }
        int take = 0, leave = 0;
        if(primes[prime_idx] <= amount)
        {
            take = findres(amount - primes[prime_idx], coins - 1, prime_idx + 1);
            leave = findres(amount, coins, prime_idx+1);
        }
        return dp[amount][coins][prime_idx] = take  + leave;
    }
    else
    {
        return 0;
    }
}
int main()
{
    fast;
    sieve();
    primes_sz = primes.size();
    memset(dp,-1,sizeof dp);
    for(int i=0 ; i<primes_sz; i++)
    {
        dp[0][0][i] = 1; //number of ways to make amount 0, using 0 coins , with any prime index is always 1
    }
    while(cin>>n>>k)
    {
        if(n==0 && k==0)
        {
            break;
        }
        cout<<findres(n,k,0)<<endl;
    }
    return 0;
}
