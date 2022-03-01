class Solution {
    int getOnesInBinary(int n){
        int ans = 0;
        while(n>0){
            int r = n%2;
            n /= 2;
            if(r == 1)
                ans++;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            ans.push_back(getOnesInBinary(i));
        }
        return ans;
    }
};