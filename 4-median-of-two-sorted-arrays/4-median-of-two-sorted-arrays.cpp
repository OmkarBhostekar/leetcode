class Solution {
public:
    vector<double> mergeVectorOn(vector<int>& nums1, vector<int>& nums2){
        vector<double> v;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i++]);
            }else{
                v.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size())
            v.push_back(nums1[i++]);
        while(j<nums2.size())
            v.push_back(nums2[j++]);
        return v;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double> v = mergeVectorOn(nums1,nums2);
        if(v.size()%2==1){
            return v[v.size()/2];
        }else{
            return (v[v.size()/2]+v[(v.size()/2)-1])/2;
        }
        return 0;
    }
};