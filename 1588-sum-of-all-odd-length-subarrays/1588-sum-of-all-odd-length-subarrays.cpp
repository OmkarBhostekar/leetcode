class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n+1,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            pre[i+1] = sum;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j+=2){
                ans += (pre[j+1]-pre[i]);
            }
        }
        return ans;
    }
};