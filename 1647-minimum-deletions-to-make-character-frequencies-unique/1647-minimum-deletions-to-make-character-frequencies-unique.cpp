class Solution {
public:
    int minDeletions(string s) {
        int n = s.length(), ans = 0;
        unordered_map<char,int> m;
        unordered_map<int,bool> seen;
        for(auto x: s) m[x]++;
        vector<int> v;
        for(auto x: m){
            v.push_back(x.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int x: v){
            if(seen[x]){
                while(x>0 and seen[x]) {
                    x--;
                    ans++;
                }
            }
            seen[x] = true;
        }
        
        return ans;
    }
};