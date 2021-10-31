class Solution { //inspiration from Kadane's algorithm
public:
    int lengthOfLongestSubstring(string s) {  // O(N) solution
        if(s.length() == 0) 
        {
            return 0;
        }
        map<char,int>m; //stores char and its latest index
        map<char,bool> exist; //stores whether certain element exists or not
        vector<int> arr; //will store indexes from which characters have no repeating values from

        for(int i=0; i<s.length(); i++)
        {
            char c= s[i];
            if(exist[c] == false)
            {
                exist[c]=true;
                m[c]=i; //its latest index;
                arr.push_back(0); //since this character is new so it has no repeating
                                  //characters since 0 idx
            }
            else //not new
            {
                int prev=m[c]; //previous index
                arr.push_back(prev+1) ;//so it has no repeating characters after 1 index from previously existing index
                m[c]=i; //update its latest index;

            }
        }
        int last_idx=0,cur=1,res=1; //calculating 1st index to be the only result substring
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i]<=last_idx) //it belongs to the 'cur' substring
            {
                cur++; //include it to the current result
            }
            else //this element wont belong to the 'cur' substring
            {
                last_idx=arr[i]; 
                cur=i-arr[i]+1; //new substring this element will be a part of
            }
            res=max(res,cur);
        }
        return res;

    }
};