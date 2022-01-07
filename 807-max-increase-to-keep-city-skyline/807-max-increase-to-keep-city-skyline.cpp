class Solution {
public:
    pair<int,int> getMax(vector<vector<int>>& grid,int r, int c,int n){
        int mr = 0, mc = 0;
        for(int i=0; i<n; i++){
            mr = max(mr,grid[r][i]);
            mc = max(mc,grid[i][c]);
        }
        return {mr,mc};
    }
    
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pair<int,int> m = getMax(grid,i,j,n);
                int x = min(m.first,m.second);
                sum += abs(x - grid[i][j]);
                grid[i][j] = x;
            }
        }
        return sum;
    }
};