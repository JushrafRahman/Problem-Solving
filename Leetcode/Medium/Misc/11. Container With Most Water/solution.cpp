class Solution { //greedy thinking
public:
    int maxArea(vector<int>& height) {
        int first=0,last=height.size()-1;
        long long res=0;
        while((first<last)&&(first<height.size()) &&(last>=0))
        {
            res=max(res,finval(first,height[first],last,height[last]));
            if(height[first]<height[last])
            {
                first++;
            }
            else if(height[first] > height[last])
            {
                last--;
            }
            else 
            {
                first++;
                last--;
            }
            
        }
        return res;
        
    }
   long long finval(int x1,int y1, int x2, int y2)
    {
        return min(y1,y2)*abs(x1-x2);
    }
};