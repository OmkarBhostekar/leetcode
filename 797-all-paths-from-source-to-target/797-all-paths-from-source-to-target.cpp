class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<vector<int>>& res, int s, int dest, vector<int> temp){
        temp.push_back(s);
        if(s == dest){
            res.push_back(temp);
            temp.clear();
        }else{
            for(auto x: g[s]){
                dfs(g,res,x,dest,temp);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> res;
        dfs(g,res,0,g.size()-1,{});
        return res;
    }
};