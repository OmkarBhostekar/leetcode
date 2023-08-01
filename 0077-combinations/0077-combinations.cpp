class Solution {
public:
    void f(vector<vector<int>> &ans, vector<int> &tmp, int i, int k, int n){
        if(tmp.size()==k){
            ans.push_back(tmp);
            return;
        }
        for(int j=i;j<=n;j++){
            tmp.push_back(j);
            f(ans,tmp,j+1,k,n);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        // for(int i=1;i<=n;i++){
        //     temp.clear();
            f(ans,temp,1,k,n);
        // }
        return ans;
    }
};