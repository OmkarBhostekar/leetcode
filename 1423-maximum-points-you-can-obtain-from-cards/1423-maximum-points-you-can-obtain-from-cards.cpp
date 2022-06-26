class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size(), total = accumulate(cp.begin(),cp.end(),0), sum=0, m = INT_MAX;
        vector<int> prefix(n+1);
        for(int i=0;i<n;i++){
            sum += cp[i];
            prefix[i+1] = sum;
        }
        k = n-k;
        for(int i=0;i<n-k+1;i++){
            m = min(m,(prefix[i+k]-prefix[i]));
        }
        
        return total-m;
    }
};