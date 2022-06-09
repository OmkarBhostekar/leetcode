class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int r=mat.size(),c=mat[0].size();
        if(t<mat[0][0] or t>mat[r-1][c-1]) return false;
        int k=0;
        while(k<r && t>=mat[k][0]) k++;
        for(auto x: mat[k-1]){
            if(t==x) return true;
        }
        return false;
    }
};