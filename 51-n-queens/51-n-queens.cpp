class Solution {
public:
    vector<vector<string>> ans;
    
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
    
    void nQueen(vector<string> &board, int i, int n, int placed){
        if(placed == n){
            ans.push_back(board);
            return;
        }
        if(i>=n) return;
        for(int k=0;k<n;k++){
            if(isValid(board, i, k, n)){
                board[i][k] = 'Q';
                nQueen(board, i+1, n, placed+1);
                board[i][k] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            board[i] = s;
        nQueen(board, 0, n, 0);
        return ans;
    }
};