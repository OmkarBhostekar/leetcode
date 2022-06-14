class Solution {
public:
    int lcs(string w1, string w2, int m, int n){
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(w1[i-1] == w2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        return m+n-2*lcs(word1,word2,m,n);
    }
};