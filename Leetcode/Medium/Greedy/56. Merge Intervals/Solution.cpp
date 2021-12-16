class Solution {
public:
   bool sort_pair(const vector<int> &a,const vector<int> &b)
    {
        return (a[0]<b[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); //, sort_pair);
        vector<vector<int>> res;
        int start = intervals[0][0];
        int fin = intervals[0][1];
        if(intervals.size() == 1)
        {
            return intervals;
        }
        else{
        for(int i=1; i<intervals.size(); i++)
        {
            int s2 = intervals[i][0];
            int f2 = intervals[i][1];
            if(s2>fin)
            {
                vector<int> x;
                x.push_back(start); x.push_back(fin);
                res.push_back(x);
                start = s2 ;
                fin = f2;
            }
            else if(fin>= s2 && f2> fin)
            {
                fin = f2;
            }
            if(i+1 == intervals.size())
                {
                 vector<int> y;
                y.push_back(start); y.push_back(fin);
                res.push_back(y);
                }
        }
        return res;
        }

    }

};