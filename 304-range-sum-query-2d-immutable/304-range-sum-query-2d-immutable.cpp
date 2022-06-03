class NumMatrix {
public:
    int m,n;
    vector<vector<int>> v;
    
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp.push_back(matrix[i][j]);
                }else if(i==0){
                    temp.push_back(temp[j-1]+matrix[i][j]);
                }else if(j==0){
                    temp.push_back(v[i-1][0]+matrix[i][j]);
                }else{
                    temp.push_back(v[i-1][j]+temp[j-1]+matrix[i][j]-v[i-1][j-1]);
                }
            }
            v.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x = v[row2][col2];
        int y=0,z=0,a=0;
        if(col1>0){
            y = v[row2][col1-1];
        }
        if(row1>0){
            z = v[row1-1][col2];
        }
        if(row1>0 and col1>0){
            a = v[row1-1][col1-1];
        }
        return (x-y-z+a);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */