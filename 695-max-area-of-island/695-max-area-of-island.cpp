class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int m, int n, int i, int j){
        if(i<0 || i>=m || j<0 || j>=n || !grid[i][j] || vis[i][j]) return 0;
        vis[i][j] = true;
        int top = dfs(grid, vis, m, n, i-1, j);
        int down = dfs(grid, vis, m, n, i+1, j);
        int left = dfs(grid, vis, m, n, i, j-1);
        int right = dfs(grid, vis, m, n, i, j+1);
        return 1 + top + down + left + right;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(!vis[i][j])
                    ans = max(ans,dfs(grid, vis, m, n, i, j));
            }
        return ans;
    }
};