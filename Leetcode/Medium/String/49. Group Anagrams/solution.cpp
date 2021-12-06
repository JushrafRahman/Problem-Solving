class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> arr; //will store the res
        
        for(int i=0; i<strs.size(); i++)
        {
            string prev_word = strs[i];
            sort(strs[i].begin(),strs[i].end());
            string word = strs[i];

            arr[word].push_back(prev_word);
        }
        vector<vector<string>> res;
        for(auto it = arr.begin(); it!= arr.end(); it++)
        {
            vector<string> v = it->second;
            res.push_back(v);
            
        }
        return res;
        
    }
};