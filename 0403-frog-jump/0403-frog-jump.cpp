class Solution {
public:
    int dp[2000][2000];
    bool canCross(vector<int>& v) {
        int n = v.size();
        if(v[1] != 1) return false;
        unordered_map<int, int> m;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i<n; i++) {
            m[v[i]] = i;
        }
        function<int(int,int)> f = [&](int i, int k){
            if(i==n-1) return 1;
            if(dp[i][k] != -1) return dp[i][k];
            // try for k
            bool k0 = false;
            bool k1 = false;
            bool k2 = false;
            if(m.find(v[i]+k) != m.end()){
                // can jump
                k0 = f(m[v[i]+k],k);
            }
            if(m.find(v[i]+k+1) != m.end()){
                // can jump
                k1 = f(m[v[i]+k+1],k+1);
            }
            if(k>1 && m.find(v[i]+k-1) != m.end()){
                // can jump
                k2 = f(m[v[i]+k-1],k-1);
            }
            dp[i][k] = k0 || k1 || k2;
            return dp[i][k];
        };
        return f(1,1);
    }
};