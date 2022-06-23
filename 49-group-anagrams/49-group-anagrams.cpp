class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(auto x: strs){
            string temp = x;
            sort(x.begin(),x.end());
            m[x].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto x: m){
            res.push_back(x.second);
        }
        return res;
    }
};