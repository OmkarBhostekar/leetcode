class Solution {
public:
    int change(int a, vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        vector<long long> dp(a+1, 0LL);
        dp[0] = 1LL;
        for(auto c: v){
            for(int am=c;am<=a;am++){
                dp[am] += dp[am-c];
            }
        }
        return dp[a];
    }
};