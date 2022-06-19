class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(),ans = INT_MAX;
        vector<int> prev = mat[m-1];
        for(int i=m-2;i>=0;i--){
            vector<int> cur(n);
            for(int j=0;j<n;j++){
                int l=INT_MAX, r=INT_MAX;
                if(j>0) l = prev[j-1];
                if(j<n-1) r = prev[j+1];
                cur[j] = mat[i][j] + min(prev[j], min(l,r));
            }
            prev = cur;
        }
        for(int j=0;j<n;j++)
            ans = min(ans, prev[j]);
        return ans;
    }
};