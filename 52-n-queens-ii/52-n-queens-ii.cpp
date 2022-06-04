class Solution {
public:
    bool isValid(vector<string> &board, int i, int j, int n){
        int row=i, col=j;
        for(int k=0;k<i; k++)
            if(board[k][j] == 'Q') return false;
        while(row>=0 and col>=0){
            if(board[row][col] == 'Q') return false;  
            row--;
            col--;
        }
        row=i, col=j;
        while(row>=0 and col<n){
            if(board[row][col] == 'Q') return false;  
            row--;
            col++;
        }
        return true;
    }
    
    void solve(vector<string> &board, int i, int n, int placed, int &ans){
        if(placed == n){
            ans++;
            return;
        }
        if(i>=n) return;
        for(int k=0;k<n;k++){
            if(isValid(board, i, k, n)){
                board[i][k] = 'Q';
                solve(board, i+1, n, placed+1, ans);
                board[i][k] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i] = s;
        solve(board, 0, n, 0, ans);
        return ans;
    }
};