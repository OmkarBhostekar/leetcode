class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> dp;
        while(n!=1 and dp.find(n) == dp.end()){
            dp[n]++;
            int sum = 0;
            while(n>0){
                sum += pow(n%10,2);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};