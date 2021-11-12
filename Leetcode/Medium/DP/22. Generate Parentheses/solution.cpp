class Solution
{
public:
    vector<string> arr;
    vector<string> generateParenthesis(int n)
    {
        string res="("; //has to start with open
        genpar(res,n,1,0);
        return arr;
    }
    void genpar(string s,int n, int open,int close)
    {
        int rem = n - (open + close); //remaining open pars
        //base case 1
        if(rem == 0) //no opening pars
        {
            //close the current one
            for(int i=0; i<open; i++)
            {
                s.push_back(')');
            }
            arr.push_back(s);
            return ; //void does not return

        }
        else //I can either open or close
        {
            //open
            genpar(s+'(',n,open+1,close);
            //close
            if(open>0)
            {
                genpar(s+')',n,open-1,close+1);
            }

        }


    }
};