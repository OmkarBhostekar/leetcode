class Solution {
public:
    int change(int a, vector<int>& v) {
        int n = v.size();
        vector<vector<long long>> dp(a+1, vector<long long>(n+1,-1LL));
        sort(v.begin(),v.end());
        function<long long(int,int)> f = [&](int am, int i){
            if(am==0) return 1LL;
            if(i==n || am<0) return 0LL;
            if(dp[am][i] != -1) return dp[am][i];
            long long ans = 0;
            for(int j=i;j<n;j++){
                if(v[i]>am) break;
                ans += f(am-v[j],j);
            }
            return dp[am][i] = ans;
        };
        return f(a,0);
    }
};