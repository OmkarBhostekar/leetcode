class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int dp[n+1][n+1];
        memset(dp, -1, sizeof dp);
        function<int(int,int)> f = [&](int i, int cnt){
            if(i==n) return 0;
            if(dp[i][cnt] != -1) return dp[i][cnt];
            int ans = INT_MIN;
            ans = cnt*v[i] + f(i+1,cnt+1);
            ans = max(ans, f(i+1,cnt));
            return dp[i][cnt] = ans;
        };
        return f(0,1);
    }
};