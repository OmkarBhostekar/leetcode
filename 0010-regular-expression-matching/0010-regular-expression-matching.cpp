class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int,int)> f = [&](int i, int j){
            if(j>m) return 0;
            if(i==n){
                int k = j;
                while(k<m){
                    if(k+1<m && p[k+1] == '*'){
                        k += 2;
                    }else return 0;
                }
                return 1;
            }
            bool p0=false,p1=false;
            if(dp[i][j] != -1) return dp[i][j];
            if(p[j] != '.' && p[j] != '*'){
                if(j+1<m && p[j+1] == '*'){
                    p0 = f(i,j+1);
                }else{
                    if(p[j] != s[i]) return 0;
                    p0 = f(i+1,j+1);
                }
            }
            if(p[j] == '.'){
                if(j+1<m && p[j+1] == '*'){
                    p0 = f(i,j+1);
                }else{
                    p0 = f(i+1,j+1);
                }
            }
            if(p[j] == '*'){
                if(p[j-1] == '.') {
                    p1 = f(i+1,j); // multi
                    p1 |= f(i+1,j+1); // single
                    p1 |= f(i,j+1);
                }else{
                    if(p[j-1] == s[i]){
                        p1 = f(i+1,j); // multi
                        p1 |= f(i+1,j+1); // single
                    }
                    p1 |= f(i,j+1);
                }
            }
            dp[i][j] = p0 || p1;
            return dp[i][j];
        };
        return f(0,0);
    }
};