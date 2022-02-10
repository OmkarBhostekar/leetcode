class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); 
        int ans = 0; 
        unordered_map<int,int> mpp;
        
        int prefix[n];
        prefix[0] = arr[0];
        for(int i=1; i<n; i++){
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        for(int i=0; i<n; i++){
            if(prefix[i] == k)
                ans++;
            if(mpp.find(prefix[i]-k) != mpp.end()){
                ans += mpp[prefix[i] - k];
            }
            mpp[prefix[i]]++;
        }
        
        
        return ans;
    }
};