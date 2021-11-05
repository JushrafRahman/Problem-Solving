class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1000+5][1000+5]; //start, end
        memset(dp, 0, sizeof dp);
        int len=s.length();
        pair<int,int> res;
        int maxi=1;
        for(int i=0 ; i<len; i++)
        {
             dp[i][i]=1; //all the chars are 1 lengthed substr itself
            res.first=i;
            res.second=i;
        }
        for(int sz=1; sz<=len;sz++) //sz= currently checking for substr of size 'sz'
        {
            for(int i=0; i<len; i++)
            {
                int start=i;
                int end=i+sz;
                if(end<len)
                {
                    //special case
                    if(sz == 1 ) //for 2 lenghted substr
                    {
                        if(s[start] == s[end])
                        {
                            dp[start][end]=1;
                            
                        }
                        
                    }
                    else
                    {
                        int mid_start=start+1;
                        int mid_end = end-1;
                        if(dp[mid_start][mid_end] == 1) //if the middle string is a pd
                        {
                            //compare the first and last char
                            if(s[start] == s[end])
                            {
                                dp[start][end] = 1; 
                            }
                            
                        }
                    }
                    int curlen=end-start+1;
                    if((curlen>maxi)&&(dp[start][end] == 1))
                    {
                        res.first = start;
                        res.second = end;
                        maxi=curlen;
                        
                    }
                }
                
            }
            
        }
        string finres= s.substr(res.first,res.second-res.first+1);
        return finres;
        
        
    }
};
/*
Idea is the dp approach. 
For example string = dabad,
If the middle string 'aba' is a palindrome, I will compare first and last char. else I wont
For string abab the middle string 'ba' is not a palinrome so I will not compare.
 
*/