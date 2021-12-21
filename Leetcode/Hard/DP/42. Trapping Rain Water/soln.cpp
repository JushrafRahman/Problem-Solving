class Solution
{
private:
    int sz;
public:
    int trap(vector<int>& height)
    {
        sz = height.size();
        if(sz<=2)
        {
            return 0;
        }
        vector<int> maxleft = height;
        vector<int> maxright = height;

        for(int i=1; i<sz ; i++)
        {
            maxleft[i] = max(maxleft[i],maxleft[i-1]);
        }
        for(int i=sz-2; i>=0 ; i--)
        {
            maxright[i] = max(maxright[i],maxright[i+1]);
        }
        int sum = 0;
        for(int i = 0 ; i<sz ; i++ )
        {
            int holds = min(maxleft[i],maxright[i]) - height[i];
            sum+=holds;
        }
        return sum;

    }
};