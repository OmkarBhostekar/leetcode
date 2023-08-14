class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x: nums){
            if(pq.size()==k){
                if(pq.top()<x){
                    pq.pop();
                    pq.push(x);
                }
            }else pq.push(x);
        }
        return pq.top();
    }
};