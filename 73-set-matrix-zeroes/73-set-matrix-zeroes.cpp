class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        unordered_set<int> x;
        unordered_set<int> y;
        for(int i=0; i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                if(m[i][j] == 0){
                    x.insert(i);
                    y.insert(j);
                }
            }
        }
        for(auto a: x){
            for(int i=0;i<m[a].size();i++)
                m[a][i] = 0;
        }
        for(auto a: y){
            for(int i=0;i<m.size();i++)
                m[i][a] = 0;
        }
    }
};