class Solution {
public:
    int maxProfit(vector<int>& p) {
        int lsf = INT_MAX;
        int pist = 0;
        int ans = 0;
        for(int i=0; i<p.size();i++){
            if(p[i] < lsf){
                lsf = p[i];
            }
            pist = p[i] - lsf;
            if(pist > ans){
                ans = pist;
            }
        }
        return ans;
    }
};