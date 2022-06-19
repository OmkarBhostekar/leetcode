class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> prev(grid[0].size(),-1);
        int sum = 0;
        for(int j=0;j<grid[0].size();j++){
            sum += grid[0][j];
            prev[j] = sum;
        }
        for(int i=1;i<grid.size();i++){
            vector<int> cur(grid[0].size(),-1);
            for(int j=0;j<grid[0].size();j++){
                if(i==0 and j==0){
                    cur[j] = grid[i][j];
                }else if(i==0){
                    cur[j] = grid[i][j] + cur[j-1];
                }else if(j==0){
                    cur[j] = grid[i][j] + prev[j];
                }else{
                    cur[j] = grid[i][j] + min(cur[j-1], prev[j]);
                }
            }
            prev = cur;
        }
        return prev[grid[0].size()-1];
    }
};