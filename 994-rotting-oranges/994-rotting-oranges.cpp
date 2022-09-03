class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> dir = {
            {-1,0},{1,0},{0,-1},{0,1}
        };
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }
        int ans = 0;
        bool flag = q.empty();
        while(!q.empty()){
            int len = q.size();
            while(len--){
                auto front = q.front();
                q.pop();
                for(auto x: dir){
                    int i=front.first+x[0],j=front.second+x[1];
                    if( i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1){
                        grid[i][j] = 2;
                        q.push({i,j});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return flag ? ans : ans-1;
    }
};