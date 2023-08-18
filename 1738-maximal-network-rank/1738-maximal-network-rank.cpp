class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& v) {
        vector<set<int>> vst(n);
        for(int i=0;i<v.size();i++){
            vst[v[i][0]].insert(i);
            vst[v[i][1]].insert(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<int> x;
                for(auto y: vst[i]) x.insert(y);
                for(auto y: vst[j]) x.insert(y);
                ans = max(ans,(int)x.size());
            }
        }
        return ans;
    }
};