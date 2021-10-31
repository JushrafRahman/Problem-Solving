class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
        {
            return 0;
        }
        vector<int> dif;
        for(int i=1; i<prices.size(); i++)
        {
            int d= prices[i] - prices[i-1]; 
            dif.push_back(d);
        }
        int res= maxsubarr(dif);
        return res;
        
    }
    int maxsubarr(vector<int> arr)
    {
        int res=arr[0];
        for(int i=1; i<arr.size(); i++)
        {
            arr[i]= max(arr[i],arr[i]+arr[i-1]);
            res=max(res,arr[i]);
        }
        if(res>0) //profit
        {
            return res;
        }
        else
        {
            return 0;
        }
    }
};