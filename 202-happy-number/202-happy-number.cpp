class Solution {
public:
    int getSquareSum(int n){
        int sum = 0;
        while(n>0){
            int last_digit = n%10;
            sum += (last_digit*last_digit);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n!=1 and seen.find(n) == seen.end()){
            seen.insert(n);
            n = getSquareSum(n);
        }
        return n == 1;
    }
};