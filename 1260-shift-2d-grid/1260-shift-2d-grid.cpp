class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n=grid[0].size();
        k = (k%(m*n));
        vector<int> v;
        for(auto x: grid){
            for(auto y: x)
                v.push_back(y);
        }
        k = v.size()-k-1;
        int i=0,j=0;
        for(int a=k+1;a<v.size();a++){
            grid[i][j] = v[a];
            j++;
            if(j>=n){
                j=0;
                i++;
            }
        }
        for(int a=0;a<=k;a++){
            grid[i][j] = v[a];
            j++;
            if(j>=n){
                j=0;
                i++;
            }
        }
        return grid;
    }
};