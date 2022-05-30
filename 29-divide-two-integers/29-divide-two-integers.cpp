class Solution {
public:
    int divide(int dv, int d) {
        if(dv == INT_MIN and d == -1) return INT_MAX;
        bool isNeg = dv>=0 == d>=0;
        long divid = labs(dv) , divi = labs(d) , result = 0;
        while(divid - divi>=0){
            int cnt=0;
            while( divid - (divi<<1<<cnt)>=0)
                cnt++;
            result+=1<<cnt;
            divid -= divi<<cnt;
        }
        return isNeg ? result : -result;
    }
};