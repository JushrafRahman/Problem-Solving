class Solution {
public:
    char arr[1010][1010];
    int len,i;
    bool valid = true;
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
         i = 0;
        len = s.length();
        fill_char();
        arr[0][0] = s[i];
        int curx,cury;
        curx = cury = 0;
        i++;
        while(i < s.length())
        {
            pair<int,int> idx,idx2;
            if(valid){
            idx = fill_down(s,curx,cury, numRows);
            }
            else
            {break;}

            if(valid){
            idx2 = fill_right(s,idx.first,idx.second,numRows);
            }
            else
            {break;}

            curx = idx2.first;
            cury = idx2.second;
        }
        string res = read_str(numRows);
        return res;


    }
    void fill_char()
    {
        for(int p=0 ; p< len; p++)
        {
            for(int q=0; q<len; q++)
            {
                arr[p][q] = '1';
            }
        }

    }
    string read_str(int row)
    {
        string res = "";
        for(int p = 0 ; p< len ; p++)
        {
            for(int q = 0 ;q < len; q++ )
            {
                if(arr[p][q] != '1')
                {
                    res.push_back(arr[p][q]);
                }
            }
        }
        return res;
    }
    pair<int,int> fill_down(string &str,int curx,int cury, int numRows)
    {
       // cout<<"at down "<<endl;
        for(int row = 1; row <= numRows - 1 ; row++)
        {
            curx += 1;
        //    cout<<"pushing idx : "<<i<<" at "<<curx<<","<<cury<<endl;
            arr[curx][cury] = str[i++];
            if(i >= len)
            {
                valid = false; //no more op will occur
                break;
            }

        }
        pair<int,int> p;
        p = make_pair(curx,cury);
        return p;

    }
        pair<int,int> fill_right(string &str,int curx,int cury, int numRows)
    {
         //       cout<<"at right "<<endl;

        for(int row = 1; row <= numRows - 1 ; row++)
        {
            curx -= 1;
            cury += 1;
      //   cout<<"pushing idx : "<<i<<" at "<<curx<<","<<cury<<endl;

            arr[curx][cury] = str[i++];
            if(i >= len)
            {
                valid = false; //no more op will occur
                break;
            }

        }
        pair<int,int> p;
        p=make_pair(curx,cury);
        return p;

    }
};