class Solution {
private:
    int arr[110][110];
    int r,c;
public:
    int uniquePaths(int m, int n) {
        r = m; c = n;
        memset(arr,-1,sizeof arr);
        long long res = find_res(1,1);
        return res;

    }
    long long find_res(int i,int j)
    {
        if(!is_valid(i,j))
        {
            return 0;
        }
        if(arr[i][j] != -1)
        {
            return arr[i][j];
        }
        if(i == r && j == c)
        {
            return arr[i][j] = 1;
        }
        long long down = find_res(i+1,j);
        long long right = find_res(i, j+1);
        return arr[i][j]= down + right;


    }
    bool is_valid(int i, int j)
    {
        if(i>=1 && i<=r && j>=1 && j<=c)
        {
            return true;
        }
        return false;
    }
};