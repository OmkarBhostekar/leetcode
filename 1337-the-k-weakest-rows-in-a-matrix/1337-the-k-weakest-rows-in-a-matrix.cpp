class Solution {
    static bool compare(pair<int,int> &a, pair<int,int> &b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vp;
        for(int i=0;i<mat.size();i++){
            int temp = 0;
            for(int y: mat[i]){
                if(y == 1) temp++;
            }
            vp.push_back({i,temp});
        }
        sort(vp.begin(),vp.end(),compare);
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};