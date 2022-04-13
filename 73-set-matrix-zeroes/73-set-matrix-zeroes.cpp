class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        vector<vector<int>> temp = m;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(temp[i][j] == 0){
                    for(int k=0;k<m[0].size();k++)
                        m[i][k] = 0;
                    for(int k=0;k<m.size();k++)
                        m[k][j] = 0;
                }
            }
        }
    }
};