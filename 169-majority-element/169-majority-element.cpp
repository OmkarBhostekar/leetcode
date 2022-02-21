class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        for(int x: nums){
            mpp[x]++;
        }
        int maxOccur = INT_MIN;
        int m;
        for(auto it: mpp){
            if(it.second >= maxOccur){
                maxOccur = it.second;
                m = it.first;
            }
        }
        return m;
    }
};