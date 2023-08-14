class Solution {
public:
    int minCost(int n, vector<int>& v) {
        v.insert(v.begin(),0);
        v.push_back(n);
        sort(v.begin(),v.end());
        vector<vector<int>> dp(110,vector<int>(110,-1));
        function<int(int,int)> f = [&](int l, int r){
            if(r-l==1) return 0;
            if(dp[l][r] != -1) return dp[l][r];
            int cost = v[r]-v[l];
            int mini = INT_MAX;
            for(int i=l+1;i<r;i++){
                mini = min(mini,cost+f(l,i)+f(i,r));
            }
            return dp[l][r] = mini;
        };
        return f(0,v.size()-1);
    }
};