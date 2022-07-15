class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) continue;
                if(i-1>=0 && !grid[i-1][j]) ans++;
                if(i+1<m && !grid[i+1][j]) ans++;
                if(j-1>=0 && !grid[i][j-1]) ans++;
                if(j+1<n && !grid[i][j+1]) ans++;
                if(i==0) ans++;
                if(i==m-1) ans++;
                if(j==0) ans++;
                if(j==n-1) ans++;
            }
        }
        return ans;
    }
};