class Solution {
public:
    int reverse(int x) {
        bool neg = x<0;
        x = abs(x);
        long long sum = 0LL;
        while(x){
            sum = sum*10+(x%10);
            x /= 10;
        }
        if(neg) sum = sum*(-1LL);
        if(sum>INT_MAX || sum<INT_MIN) return 0;
        return int(sum);
    }
};