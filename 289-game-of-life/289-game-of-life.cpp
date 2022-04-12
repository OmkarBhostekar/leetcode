class Solution {
public:
    int getNeighborCount(int i,int j, int m, int n, vector<vector<int>>& b){
        int c=0;
        if(j-1>=0 and b[i][j-1] == 1) c++;
        if(j+1<n and b[i][j+1] == 1) c++;
        if(i-1>=0 and b[i-1][j] == 1) c++;
        if(i+1<m and b[i+1][j] == 1) c++;
        if(i-1>=0 and j-1>=0 and b[i-1][j-1] == 1) c++;
        if(i+1<m and j-1>=0 and b[i+1][j-1] == 1) c++;
        if(i-1>=0 and j+1<n and b[i-1][j+1] == 1) c++;
        if(i+1<m and j+1<n and b[i+1][j+1] == 1) c++;
        return c;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        int temp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = 0;
                int x = getNeighborCount(i,j,m,n,board);
                if(board[i][j] == 1){
                    if(x<2 or x>3){
                        temp[i][j] = 0;
                    }else
                        temp[i][j] = 1;
                }
                if(board[i][j] == 0 && x == 3){
                    temp[i][j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = temp[i][j];
            }
        }
    }
};