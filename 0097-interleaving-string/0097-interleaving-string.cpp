class Solution {
public:
    bool f(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp){
        if(k == s3.size()){
            return i == s1.size() && j == s2.size();
        }
        if(dp[k][i][j] != -1) return dp[k][i][j];
        if(i<s1.size() && s1[i] == s3[k] && f(s1,s2,s3,i+1,j,k+1,dp)) 
            return dp[k][i][j] = true;
        if(j<s2.size() && s2[j] == s3[k] && f(s1,s2,s3,i,j+1,k+1,dp)) 
            return dp[k][i][j] = true;
        return dp[k][i][j] = false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s3.size()+1,vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,-1)));
        
        return f(s1,s2,s3,0,0,0,dp);
    }
};