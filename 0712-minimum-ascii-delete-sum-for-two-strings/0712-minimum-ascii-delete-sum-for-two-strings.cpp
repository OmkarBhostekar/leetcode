class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int sum = 0;
        vector<int> sf1(n+1,0);
        for(int i=n-1;i>=0;i--){
            sum += s1[i];
            sf1[i] = sum;
        }
        sum = 0;
        vector<int> sf2(m+1,0);
        for(int i=m-1;i>=0;i--){
            sum += s2[i];
            sf2[i] = sum;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> f = [&](int i, int j){
            if(i==n && j==m) return 0;
            if(i==n || j==m){
                if(i==n) return sf2[j];
                return sf1[i];
            }
            if(dp[i][j] != -1) return dp[i][j];
            if(s1[i] == s2[j]){
                return dp[i][j] = f(i+1,j+1);
            }
            return dp[i][j] = min(((int)s1[i])+f(i+1,j),((int)s2[j])+f(i,j+1));
        };
        return f(0,0);
    }
};