class Solution {
public:
    
    string checkResult(vector<vector<int>> &mat){
        if((mat[1][1] != -1 && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) || (mat[1][1] != -1 && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]))
            return mat[1][1] == 1 ? "A" : "B";
        for(int i=0;i<3;i++){
            if(mat[i][0] != -1 && mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2])
                return mat[i][0] == 1 ? "A" : "B";
            
            if(mat[0][i] != -1 && mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i])
                return mat[0][i] == 1 ? "A" : "B";
        }
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(mat[i][j] == -1)
                    return "Pending";
        return "Draw";
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> mat(3,vector<int>(3,-1));
        bool isX = true;
        for(auto move: moves){
            mat[move[0]][move[1]] = isX;
            isX = !isX;
        }
        return checkResult(mat);
    }
};