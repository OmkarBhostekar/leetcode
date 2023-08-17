class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e6));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j] = (v[i][j] == 0 ? 0 : 1e6);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(i>0) ans[i][j] = min(ans[i][j],1+ans[i-1][j]);
                if(j>0) ans[i][j] = min(ans[i][j],1+ans[i][j-1]);
            }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i<n-1) ans[i][j] = min(ans[i][j],1+ans[i+1][j]);
                if(j<m-1) ans[i][j] = min(ans[i][j],1+ans[i][j+1]);
            }
        }
        return ans;
    }
};