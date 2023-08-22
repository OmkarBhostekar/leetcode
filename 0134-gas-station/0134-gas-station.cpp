class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, cur = 0, ans = 0;
        for(int i=0;i<gas.size();i++){
            sum += gas[i];
            sum -= cost[i];
            cur += gas[i]-cost[i];
            if(cur<0){
                ans = i+1;
                cur = 0;
            }
        }
        return sum >= 0 ? ans : -1;
    }
};