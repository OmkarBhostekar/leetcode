class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
        for(int i=0;i<32;i+=2)if(n==1<<i)return true;
        return false;
    }
};