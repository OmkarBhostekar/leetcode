class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        res.push_back({1,1});
        for(int i=2;i<=rowIndex; i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<res[i-1].size();j++)
                temp.push_back(res[i-1][j-1]+res[i-1][j]);
            temp.push_back(1);
            res.push_back(temp);
        }
        return res[rowIndex];
    }
};