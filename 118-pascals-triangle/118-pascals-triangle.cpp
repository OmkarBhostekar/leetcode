class Solution {
public:
    vector<vector<int>> generate(int r) {
        vector<vector<int>> ans(r);
        ans[0] = {1};
        if(r == 1) return ans;
        for(int i=1;i<r;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<ans[i-1].size()-1;j++){
                temp.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            temp.push_back(1);
            ans[i] = temp;
        }
        return ans;
    }
};