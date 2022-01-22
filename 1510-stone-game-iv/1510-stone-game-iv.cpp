class Solution {
public:
    bool dp[100000];
    bool winnerSquareGame(int n) {
        if(dp[n] != NULL)
            return dp[n];
        bool aliceWins = false;
        for(int i=1; (n-i*i) >= 0; ++i){
            if(n-i*i == 0){
                aliceWins = true;
                break;
            }else{
                aliceWins = aliceWins || !winnerSquareGame(n-i*i);
            }
        }
        dp[n] = aliceWins;
        return aliceWins;
    }
};