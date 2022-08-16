class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> m;
        for(int i=0;i<s.length();i++)
            m[s[i]].push_back(i);
        int ans = INT_MAX;
        for(auto y: m)
            if(y.second.size() == 1 && ans>y.second[0]){
                ans = y.second[0];
            }
        return ans == INT_MAX ? -1 : ans;
    }
};