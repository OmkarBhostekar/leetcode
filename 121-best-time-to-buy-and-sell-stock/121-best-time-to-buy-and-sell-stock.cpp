class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int curr = 0;
        for(int i=0;i<prices.size()-1;i++){
            int x = curr + (prices[i+1]-prices[i]);
            if(x<0){
                curr = 0;
            }else{
                curr = x;
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};