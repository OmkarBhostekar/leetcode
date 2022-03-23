class Solution {
public:
    int brokenCalc(int s, int t) {
        if(s>=t) return s-t;
        if(t%2 == 0){
            return 1 + brokenCalc(s,t/2);
        }else{
            return 1 + brokenCalc(s,t+1);
        }
    }
};