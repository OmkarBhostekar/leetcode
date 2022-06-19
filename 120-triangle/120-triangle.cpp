class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> prev = t[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int> cur(n);
            for(int j=0;j<=i;j++){
                cur[j] = t[i][j]+ min(prev[j],prev[j+1]);
            }
            prev = cur;
        }
        return prev[0];
    }
};