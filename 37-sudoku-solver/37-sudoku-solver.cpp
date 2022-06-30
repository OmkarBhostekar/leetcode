class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j, int val){
        for(int k=0;k<9;k++){
            if((board[i][k] != '.' and (board[i][k]-'0') == val) || (board[k][j] != '.' and (board[k][j]-'0' == val))) return false;
        }
        int x = (i/3)*3, y = (j/3)*3;
        for(int a=0;a<3;a++){
            for(int b=0;b<3;b++){
                if(board[x+a][y+b] != '.' && (board[x+a][y+b]-'0') == val) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j){
        if(i>8) return true;
        int m=i,n=j+1;
        if(n>8) n=0,m++;
        if(board[i][j] != '.') return solve(board,m,n);
        for(int k=1;k<=9;k++){
            if(isValid(board, i, j, k)){
                board[i][j] =  (char)'0'+k;
                if(solve(board,m,n)) return true;
                board[i][j] =  '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};