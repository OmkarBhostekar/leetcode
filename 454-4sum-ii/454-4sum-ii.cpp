class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count = 0;
        map<int,int> mpp;
        for(int k=0; k<n; k++){
            for(int l=0; l<n; l++){
                int sum = nums3[k] + nums4[l];
                mpp[sum]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int sn = 0 - nums1[i] - nums2[j];
                count += mpp[sn];
            }
        }
        return count;
    }
};