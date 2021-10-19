class Solution
{
public:
    vector<vector<int>> res[550];
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        for(int j=0; j<candidates.size(); j++)
        {
            int coin=candidates[j];
            for(int amount=1; amount<=target; amount++)
            {
                if(amount>=coin)
                {
                    int sub=amount-coin;
                    if(sub==0)
                    {
                        vector<int> vnew= {coin};
                        res[amount].push_back(vnew); //pushing vector as element of another vector

                    }
                    else if(!res[sub].empty())
                    {
                        vector<vector<int>>vvec = res[sub]; //copying the solved vec of vecs  vvec
                        //now concat coin to each vectors of vvec
                        concat_stuff(vvec,coin,amount);


                    }


                }

            }
        }
        //printres();
      vector<vector<int>> finres;
      for(int i=0;i<res[target].size();i++)
      {
        vector<int> x=res[target][i];
        finres.push_back(x);
      }
      return finres;



    }
    void concat_stuff(vector<vector<int>>&vvec, int coin,int amount )
    {
        for(int i=0;i<vvec.size();i++) //visit each vectors inside vvec
        {
            vector<int> x= vvec[i];
            x.push_back(coin); //push it to the main res array
            //vvec[i]=x;
            res[amount].push_back(x); //pushing vector to the main res;

        }

    }


};