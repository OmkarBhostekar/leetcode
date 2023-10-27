class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int m = 1;
        string ans = "";
        ans += s[0];
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
            if(i<n-1 && s[i] == s[i+1]){
                dp[i][i+1] = 1;
                m = 2;
                ans = s.substr(i,2);
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if((j-i+1)>=m){
                        ans = s.substr(i,j-i+1);
                        m = j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};